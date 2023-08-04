/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 20:46:05 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/03 17:56:34 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../minishell.h"

int	redir_create_app(t_token *token)
{
	int	fd;

	fd = open(token->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("minishell :", 2);
		perror(token->content);
	}
	return (fd);
}

int	redir_create_out(t_token *token)
{
	int	fd;

	fd = open(token->content, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("minishell :", 2);
		perror(token->content);
	}
	return (fd);
}

int	redir_create_in(t_token *token)
{
	int	fd;

	fd = open(token->content, O_RDONLY, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("minishell :", 2);
		perror(token->content);
	}
	return (fd);
}

int	redir_create(t_token *token)
{
	if (token->type == T_REDIR_IN)
		return (redir_create_in(token));
	else if (token->type == T_REDIR_OUT)
		return (redir_create_out(token));
	else if (token->type == T_REDIR_APP)
		return (redir_create_app(token));
	return (-4);
}

t_fd	create_heredoc(t_token *token)
{
	t_fd	fd;
	int		pipe_fd[2];

	fd.in = -1;
	fd.out = -1;
	if (pipe(pipe_fd) == -1)
	{
		ft_putstr_fd("minishell: ", 2);
		perror(token->content);
		return (fd);
	}
	if (here_doc(pipe_fd, token))
	{
		fd.in = pipe_fd[0];
		fd.out = pipe_fd[1];
	}
	return (fd);
}
