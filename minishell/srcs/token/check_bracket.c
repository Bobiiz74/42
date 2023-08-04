/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bracket.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:27:30 by ppotier           #+#    #+#             */
/*   Updated: 2023/07/16 17:48:58 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	token_is_control(t_token *tok)
{
	if (!tok)
		return (0);
	return (tok->type == T_PIPE);
}

int	check_bracket_num(t_token **token)
{
	int	i;
	int	b_o;
	int	b_c;

	i = -1;
	b_c = 0;
	b_o = 0;
	while (token[++i])
	{
		if (token[i]->type == T_BRACKET_OPN)
			b_o++;
		if (token[i]->type == T_BRACKET_CLSE)
			b_c++;
	}
	if (b_c != b_o)
	{
		ft_put_error("syntax error", "unmatched bracket");
		return (0);
	}
	return (1);
}

int	check_bracket_o(t_token **token)
{
	int	i;

	i = -1;
	while (token[++i])
	{
		if (token[i]->type == T_BRACKET_OPN)
		{
			if (i != 0 && !token_is_control(token[i - 1])
				&& token[i - 1]->type != T_BRACKET_OPN)
			{
				ft_put_error("syntax error", "Invalid bracket");
				return (0);
			}
		}
	}
	return (1);
}

int	check_bracket_c(t_token **token)
{
	int	i;

	i = -1;
	while (token[++i + 1])
	{
		if (token[i]->type == T_BRACKET_CLSE)
		{
			if (!token_is_control(token[i + 1])
				&& token[i + 1]->type != T_BRACKET_CLSE)
			{
				ft_put_error("syntax error", "Invalid bracket");
				return (0);
			}
		}
	}
	return (1);
}
