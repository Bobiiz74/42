/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:45:43 by ppotier           #+#    #+#             */
/*   Updated: 2023/07/27 15:15:14 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	restore_fds(t_node *root, int fd_out, int fd_in)
{
	if (root->redir_fd_in != -1)
	{
		if (dup2(fd_in, STDIN_FILENO) == -1)
			perror("dup2 error");
		close(fd_in);
	}
	if (root->redir_fd_out != -1)
	{
		if (dup2(fd_out, STDOUT_FILENO) == -1)
			perror("dup2 error");
		close(fd_out);
	}
}

void	setup_node(t_node *root, t_tmp *tmp)
{
	root->pid = -1;
	root->fd_in = STDIN_FILENO;
	root->fd_in = STDOUT_FILENO;
	root->redir_fd_in = -1;
	root->redir_fd_out = -1;
	root->pipe_index = tmp->p;
	root->pipe_count = tmp->pipe_count;
	root->all_pipe = tmp->all_pipes;
	root->all_redir = tmp->all_redir;
	root->redir_pos = tmp->redir_pos;
	root->exit_status = -1;
}

int	here_doc(int pipe_fd[2], t_token *token)
{
	char	*stop;
	char	*cur_line;

	stop = token->content;
	cur_line = readline("heredoc: > ");
	if (!cur_line)
		return (0);
	while (cur_line && ft_strncmp(cur_line, stop,
			max(ft_strlen(cur_line), ft_strlen(stop))) != 0)
	{
		write(pipe_fd[1], cur_line, ft_strlen(cur_line));
		write(pipe_fd[1], "\n", 1);
		free(cur_line);
		cur_line = readline("> ");
	}
	free(cur_line);
	return (1);
}

t_node	*ast_node_create(t_token **token, int start, int size, t_tmp tmp)
{
	t_node	*root;
	int		ty_pos;

	root = malloc(sizeof(t_node));
	if (!root)
		return (NULL);
	ty_pos = find_type(root, token, start, size);
	setup_node(root, &tmp);
	if (ty_pos != -1)
	{
		root->children[0] = ast_node_create(token, start, ty_pos - start, tmp);
		root->children[1] = ast_node_create(token, ty_pos + 1,
				size - (ty_pos - start) - 1, tmp);
	}
	else
	{
		if (!node_gen_redir(root, token, start, size))
			root->type = AST_INVALID;
		nd_generate_content(root, token, start, size);
	}
	return (root);
}

void	node_destroy(t_node *root)
{
	if (!root)
		return ;
	if (root->type == AST_CMD || root->type == AST_BUILTIN)
		free(root->content);
	if (root->type == AST_ROOT)
	{
		free(root->all_pipe);
		free(root->pipe_index);
		free(root->all_redir);
		free(root->redir_pos);
	}
	node_destroy(root->children[0]);
	node_destroy(root->children[1]);
	free(root);
}
