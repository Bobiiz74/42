/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:31:45 by ppotier           #+#    #+#             */
/*   Updated: 2023/07/16 18:05:37 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	count_pipes(t_token **token)
{
	int	i;
	int	size;
	int	count;

	size = token_size(token);
	i = -1;
	count = 0;
	while (++i < size)
	{
		if (token[i]->type == T_PIPE)
			count++;
	}
	return (count);
}

void	setup_pipe(t_node *root, t_token **token, t_tmp *tmp)
{
	int	i;

	root->pipe_index = malloc(sizeof(int));
	root->pipe_count = count_pipes(token);
	root->all_pipe = malloc(sizeof(int) * (2 * root->pipe_count));
	tmp->p = root->pipe_index;
	tmp->pipe_count = root->pipe_count;
	tmp->all_pipes = root->all_pipe;
	if (!root->pipe_index || !root->all_pipe)
		return ;
	i = -1;
	while (++i < root->pipe_count)
		pipe(root->all_pipe + (i * 2));
	*(root->pipe_index) = 0;
}
