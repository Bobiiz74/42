/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agregate_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:13:21 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/03 16:55:11 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	replace_rest(t_token **token, int pos)
{
	if (token[pos])
		destroy_token(token[pos]);
	while (token[pos] && token[pos + 1])
	{
		token[pos] = token[pos + 1];
		pos++;
	}
	token[pos] = NULL;
}

void	agregate_redir(t_token ***token)
{
	int	i;

	i = 0;
	while ((*token)[i])
	{
		if (is_redir((*token)[i]))
		{
			free((*token)[i]->content);
			if ((*token)[i + 1])
				(*token)[i]->content = ft_strdup((*token)[i + 1]->content);
			else
				(*token)[i]->content = NULL;
			replace_rest(*token, i + 1);
		}
		i++;
	}
}
