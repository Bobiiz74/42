/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:33:14 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/03 17:46:53 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ast_close_pipe(t_node *root)
{
	int	i;

	if (!root)
		return ;
	i = -1;
	while (++i < root->pipe_count * 2)
		close(root->all_pipe[i]);
}

void	ast_close_redir(t_node *root)
{
	int	i;

	if (!root)
		return ;
	i = -1;
	while (root->all_redir[++i] != -2)
	{
		if (root->all_redir[i] != -1)
			close(root->all_redir[i]);
	}
}

int	ast_node_redirect(t_node *root)
{
	if (!root)
		return (1);
	if (root->redir_fd_in == -1)
		dup2(root->fd_in, STDIN_FILENO);
	if (root->redir_fd_out == -1)
		dup2(root->fd_out, STDOUT_FILENO);
	if (root->redir_fd_in != -1)
		dup2(root->redir_fd_in, STDIN_FILENO);
	if (root->redir_fd_out != -1)
		dup2(root->redir_fd_out, STDOUT_FILENO);
	ast_close_pipe(root);
	ast_close_redir(root);
	return (0);
}

void	ast_execute_built(t_node *root)
{
	t_builtin	*content;
	int			status;
	int			out_fd;
	int			in_fd;

	if (root->pipe_count > 0)
		root->pid = fork();
	if (root->pid == 0)
	{
		ast_node_redirect(root);
		content = (t_builtin *) root->content;
		status = content->func_pointer(content->args);
		exit(status);
	}
	else if (root->pid == -1)
	{
		out_fd = dup(STDOUT_FILENO);
		in_fd = dup(STDIN_FILENO);
		ast_node_redirect(root);
		content = (t_builtin *) root->content;
		root->exit_status = content->func_pointer(content->args);
		restore_fds(root, out_fd, in_fd);
	}
}

void	ast_execute(t_node *root)
{
	if (!root)
		return ;
	if (root->type == AST_ROOT)
	{
		ast_execute(root->children[0]);
		return ;
	}
	if (root->type == AST_PIPE)
		handle_pipe(root);
	ast_execute(root->children[0]);
	ast_execute(root->children[1]);
	if (root->type == AST_CMD)
		ast_execute_cmd(root);
	else if (root->type == AST_BUILTIN)
		ast_execute_built(root);
	else if (root->type == AST_NOTHING)
		root->exit_status = 0;
}
