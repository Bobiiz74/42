/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_word_around.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:13:25 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/03 18:00:24 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_word_around(t_token **token, int pos)
{
	int	i;
	int	valid_r;
	int	valid_l;

	valid_l = 0;
	valid_r = 0;
	i = pos;
	while (token[++i])
	{
		if (token[i]->type == T_WORD || is_redir(token[i]))
			valid_r = 1;
		else if (token[i]->type == T_PIPE)
			break ;
	}
	i = pos;
	while (--i >= 0)
	{
		if (token[i]->type == T_WORD || is_redir(token[i]))
			valid_l = 1;
		else if (token[i]->type == T_PIPE)
			break ;
	}
	return (valid_l && valid_r);
}
