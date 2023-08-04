/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:40:47 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/04 15:56:31 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_valid(t_node *root, int depth)
{
	static int	valid;

	if (!root)
		return (0);
	if (depth == 0)
		valid = 1;
	if (root->type == AST_ROOT)
		check_valid(root->children[0], depth + 1);
	else
	{
		check_valid(root->children[0], depth + 1);
		check_valid(root->children[1], depth + 1);
	}
	if (root->type == AST_INVALID)
		valid = 0;
	return (valid);
}

static int	check_setup(t_node *root)
{
	if (!root->all_redir || !root->redir_pos)
		return (0);
	else if (!root->pipe_index)
		return (0);
	else if (!root->all_pipe && root->pipe_count != 0)
		return (0);
	return (1);
}

t_node	*ast_generate(t_token **token)
{
	t_node	*root;
	int		size;
	t_tmp	tmp;

	g_env.g_minishell_status = 0;
	size = token_size(token);
	if (size == 0)
		return (NULL);
	root = malloc(sizeof(t_node));
	if (!root)
		return (NULL);
	root->type = AST_ROOT;
	root->content = NULL;
	setup_pipe(root, token, &tmp);
	setup_redir(root, token, &tmp);
	root->children[0] = NULL;
	root->children[1] = NULL;
	if (!check_setup(root))
	{
		node_destroy(root);
		return (NULL);
	}
	root->children[0] = ast_node_create(token, 0, size, tmp);
	return (root);
}

int	ast_init(t_node **root, t_token **token)
{
	*root = ast_generate(token);
	if (!check_valid(*root, 0))
	{
		g_env.g_minishell_status = 1;
		node_destroy(*root);
		tokens_destroy(token);
		return (0);
	}
	tokens_destroy(token);
	return (1);
}
