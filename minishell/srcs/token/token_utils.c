/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:07:58 by ppotier           #+#    #+#             */
/*   Updated: 2023/07/16 17:56:33 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	agreg_to_word(t_token **token, int *pos)
{
	char	*tmp;
	int		i;

	i = *pos;
	if (!token[*pos]->rmv)
	{
		tmp = token[*pos]->content;
		token[*pos]->content = ft_strjoin(tmp, token[*pos + 1]->content);
		free(tmp);
		destroy_token(token[*pos + 1]);
		while (token[++i])
			token[i] = token[i + 1];
	}
	else
		(*pos)++;
}

void	remove_spaces(t_token **agreg, t_token **token, int *i, int *j)
{
	agreg[(*j)++] = token[*i];
	if (token[*i + 1] && token[*i + 1]->type == T_SPACE)
	{
		destroy_token(token[*i + 1]);
		*i += 2;
	}
	else
		*i += 1;
}

void	remove_useless(t_token **token)
{
	int	i;
	int	j;

	i = -1;
	while (token[++i])
	{
		while (token[i] && token[i]->rmv)
		{
			j = 0;
			destroy_token(token[i]);
			while (token[i + j])
			{
				token[i + j] = token[i + j + 1];
				j++;
			}
		}
	}
}

// enleve les espaces entre les token;
t_token	**agregate_spaces(t_token **token, int size)
{
	t_token	**agreg;
	int		i;
	int		j;

	agreg = malloc((size + 1) * sizeof(t_token *));
	if (!agreg)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		if (!token[i])
			break ;
		if (token[i + 1] && token[i]->type == T_WORD
			&& token[i + 1]->type == T_WORD)
			agreg_to_word(token, &i);
		else
			remove_spaces(agreg, token, &i, &j);
	}
	agreg[j] = NULL;
	free(token);
	return (agreg);
}
