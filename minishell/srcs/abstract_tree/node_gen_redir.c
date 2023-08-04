/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_gen_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:17:52 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/03 17:57:04 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	redir_heredoc(t_token **tokens, t_node *root, int i, int start)
{
	t_fd	fd;

	fd = create_heredoc(tokens[i + start]);
	root->redir_fd_in = fd.in;
	root->all_redir[(*(root->redir_pos))++] = fd.in;
	root->all_redir[(*(root->redir_pos))++] = fd.out;
	root->all_redir[(*(root->redir_pos))] = -2;
	return (fd.in != -1 && fd.out != -1);
}

int	redir_out(t_token **tokens, t_node *root, int i, int start)
{
	root->redir_fd_out = redir_create(tokens[i + start]);
	root->all_redir[(*(root->redir_pos))++] = root->redir_fd_out;
	root->all_redir[(*(root->redir_pos))] = -2;
	return (root->redir_fd_out != -1);
}

int	redir_in(t_token **token, t_node *root, int i, int start)
{
	root->redir_fd_in = redir_create(token[i + start]);
	root->all_redir[(*(root->redir_pos))++] = root->redir_fd_in;
	root->all_redir[(*(root->redir_pos))] = -2;
	return (root->redir_fd_in != -1);
}

int	node_gen_redir(t_node *root, t_token **token, int start, int size)
{
	int			i;
	static int	status;

	if (start == 0)
		status = 1;
	if (!status)
		return (1);
	i = -1;
	while (++i < size)
	{
		if (token[i + start]->type == T_REDIR_IN)
			status = redir_in(token, root, i, start);
		if (token[i + start]->type == T_HEREDOC)
			status = redir_heredoc(token, root, i, start);
		if (token[i + start]->type == T_REDIR_OUT
			|| token[i]->type == T_REDIR_APP)
			status = redir_out(token, root, i, start);
		if (!status)
			break ;
	}
	return (status);
}
