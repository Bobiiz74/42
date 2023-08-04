/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_root_gen_built.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 23:18:43 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/04 14:49:56 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	func_from_name(t_builtin *content, char *cmd_name)
{
	if (ft_strncmp(cmd_name, "echo", ft_strlen("echo")) == 0)
		content->func_pointer = ft_echo;
	else if (!ft_strncmp(cmd_name, "pwd", ft_strlen("pwd")))
		content->func_pointer = ft_pwd;
	else if (!ft_strncmp(cmd_name, "cd", ft_strlen("cd")))
		content->func_pointer = ft_cd;
	else if (!ft_strncmp(cmd_name, "export", ft_strlen("export")))
		content->func_pointer = ft_export;
	else if (!ft_strncmp(cmd_name, "unset", ft_strlen("unset")))
		content->func_pointer = ft_unset;
	else if (!ft_strncmp(cmd_name, "env", ft_strlen("env")))
		content->func_pointer = ft_env;
	else if (!ft_strncmp(cmd_name, "exit", ft_strlen("exit")))
		content->func_pointer = ft_exit;
}

void	ast_root_gen_built(t_node *root, t_token **token, int start, int size)
{
	t_builtin	*content;
	int			pos;
	char		*cmd_name;

	content = malloc(sizeof(t_builtin));
	if (!content)
		return ;
	pos = ast_find_name_pos(token, start, size);
	if (pos != -1)
	{
		cmd_name = token[pos]->content;
		func_from_name(content, cmd_name);
	}
	content->args = ast_gen_args(token, start, size);
	root->content = content;
}
