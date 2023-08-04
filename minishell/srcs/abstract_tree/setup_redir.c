/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:32:55 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/03 17:45:59 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	count_redirs(t_token **token)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (token[++i])
	{
		if (is_redir(token[i]))
			count++;
		if (token[i]->type == T_HEREDOC)
			count++;
	}
	return (count);
}

void	setup_redir(t_node *root, t_token **token, t_tmp *tmp)
{
	int	i;
	int	size;

	size = count_redirs(token) + 1;
	root->all_redir = malloc(sizeof(int) * size);
	root->redir_pos = malloc(sizeof(int));
	tmp->all_redir = root->all_redir;
	tmp->redir_pos = root->redir_pos;
	if (!root->all_redir || !root->redir_pos)
		return ;
	i = -1;
	while (++i < size)
		root->all_redir[i] = -2;
	*(root->redir_pos) = 0;
}
