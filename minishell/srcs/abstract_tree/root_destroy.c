/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:18:31 by ppotier           #+#    #+#             */
/*   Updated: 2023/07/28 15:22:28 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	free_content(t_node *root)
{
	if (root->type == AST_CMD)
	{
		free(((t_cmd *) root->content)->cmd_name);
		free_args(((t_cmd *) root->content)->args);
	}
	else
		free_args(((t_builtin *) root->content)->args);
	free(root->content);
}

void	root_destroy(t_node *root)
{
	if (!root)
		return ;
	if (root->type == AST_CMD || root->type == AST_BUILTIN)
		free_content(root);
	if (root->type == AST_ROOT)
	{
		free(root->all_pipe);
		free(root->pipe_index);
		free(root->all_redir);
		free(root->redir_pos);
	}
	root_destroy(root->children[0]);
	root_destroy(root->children[1]);
	free(root);
}
