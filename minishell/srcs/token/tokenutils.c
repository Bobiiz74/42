/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:05:32 by ppotier           #+#    #+#             */
/*   Updated: 2023/07/15 18:46:38 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// donne la size du token;
int	token_size(t_token **token)
{
	int	size;

	if (!token)
		return (0);
	size = 0;
	while (token[size])
		size++;
	return (size);
}

// check si ce sont des quote, ou des var et le transforme en T_WORD;
void	to_word(t_token **token)
{
	int	i;
	int	size;

	i = -1;
	size = token_size(token);
	while (++i < size)
	{
		if (token[i]->type == T_S_QUOTE || token[i]->type == T_D_QUOTE
			|| token[i]->type == T_VAR)
			token[i]->type = T_WORD;
	}
}
