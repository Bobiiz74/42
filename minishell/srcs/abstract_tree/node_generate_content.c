/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_generate_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 22:42:58 by ppotier           #+#    #+#             */
/*   Updated: 2023/07/28 14:53:19 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**ast_gen_args(t_token **token, int start, int size)
{
	char	**args;
	int		pos;
	int		i;

	args = malloc((size + 1) * sizeof(char *));
	if (!args)
		return (NULL);
	i = 0;
	pos = ast_find_name_pos(token, start, size);
	while (pos != -1)
	{
		args[i++] = ft_strdup(token[pos]->content);
		pos = ast_find_name_pos(token, pos + 1, size - (pos - start) - 1);
	}
	args[i] = NULL;
	return (args);
}

int	ast_find_name_pos(t_token **token, int start, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i == 0 && token[i + start]->type == T_WORD)
			return (i + start);
		else if (token[i + start]->type == T_WORD
			&& !is_redir(token[i + start]))
			return (i + start);
		i++;
	}
	return (-1);
}

void	ast_root_gen_cmd(t_node *root, t_token **token, int start, int size)
{
	t_cmd	*cmd;
	int		pos;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return ;
	pos = ast_find_name_pos(token, start, size);
	if (pos != -1)
		cmd->cmd_name = ft_strdup(token[pos]->content);
	cmd->args = ast_gen_args(token, start, size);
	root->content = cmd;
}

t_node_type	find_execute_type(t_token **token, int start, int size)
{
	t_node_type		type;
	int				i;

	i = start;
	type = AST_CMD;
	while (i < size + start && (token[i]->type != T_WORD
			|| is_redir(token[i])))
		i++;
	if (!token[i] || token[i]->type != T_WORD)
		return (AST_NOTHING);
	if (!ft_strncmp(token[i]->content, "echo", ft_strlen("echo") + 1))
		type = AST_BUILTIN;
	else if (!ft_strncmp(token[i]->content, "cd", ft_strlen("cd") + 1))
		type = AST_BUILTIN;
	else if (!ft_strncmp(token[i]->content, "pwd", ft_strlen("pwd") + 1))
		type = AST_BUILTIN;
	else if (!ft_strncmp(token[i]->content, "export", ft_strlen("export") + 1))
		type = AST_BUILTIN;
	else if (!ft_strncmp(token[i]->content, "unset", ft_strlen("unset") + 1))
		type = AST_BUILTIN;
	else if (!ft_strncmp(token[i]->content, "env", ft_strlen("env") + 1))
		type = AST_BUILTIN;
	else if (!ft_strncmp(token[i]->content, "exit", ft_strlen("exit") + 1))
		type = AST_BUILTIN;
	return (type);
}

void	nd_generate_content(t_node *root, t_token **token, int start, int size)
{
	if (root->type != AST_INVALID)
		root->type = find_execute_type(token, start, size);
	if (root->type == AST_CMD)
		ast_root_gen_cmd(root, token, start, size);
	else if (root->type == AST_BUILTIN)
		ast_root_gen_built(root, token, start, size);
	root->children[0] = NULL;
	root->children[1] = NULL;
}
