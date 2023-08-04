/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:42:21 by ppotier           #+#    #+#             */
/*   Updated: 2023/07/27 17:00:11 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	handle_first_pipe(t_node *root)
{
	root->children[0]->fd_in = STDIN_FILENO;
	root->children[0]->fd_out = root->all_pipe[*(root->pipe_index) + 1];
	if (root->pipe_count == 1)
	{
		root->children[1]->fd_in = root->all_pipe[*(root->pipe_index)];
		root->children[1]->fd_out = STDOUT_FILENO; 
	}
	else
	{
		root->children[1]->fd_in = root->all_pipe[*(root->pipe_index)];
		root->children[1]->fd_out = root->all_pipe[*(root->pipe_index) + 3];
	}
}

static void	handle_last_pipe(t_node *root)
{
	root->children[0]->fd_in = root->fd_in;
	root->children[0]->fd_out = root->all_pipe[*(root->pipe_index) + 1];
	root->children[1]->fd_in = root->all_pipe[*(root->pipe_index)];
	root->children[1]->fd_out = STDOUT_FILENO;
}

static void	handle_default_pipe(t_node *root)
{
	root->children[0]->fd_in = root->fd_in;
	root->children[0]->fd_out = root->all_pipe[*(root->pipe_index) + 1];
	root->children[1]->fd_in = root->all_pipe[*(root->pipe_index)];
	root->children[1]->fd_out = root->all_pipe[*(root->pipe_index) + 3];
}

void	handle_pipe(t_node *root)
{
	if (!root)
		return ;
	if (*(root->pipe_index) == 0)
		handle_first_pipe(root);
	else if (*(root->pipe_index) == (root->pipe_count * 2) - 2)
		handle_last_pipe(root);
	else
		handle_default_pipe(root);
	*(root->pipe_index) += 2;
}
