/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_sq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:56:10 by ppotier           #+#    #+#             */
/*   Updated: 2023/07/14 11:57:19 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// genere le token "T_SPACE"
void	ft_space(t_tokenizer *tok, t_token *token)
{
	token->type = T_SPACE;
	while (tok->input[tok->index] == ' ' || tok->input[tok->index] == '\t')
		tok->index += 1;
	generate_token(token, " ", 1);
}

// genere token simple quote si il trouve le 2eme, sinon -> invalid;
void	simple_quote(t_tokenizer *tok, t_token *token)
{
	char	*end_sq;
	int		size;

	token->type = T_S_QUOTE;
	tok->index += 1;
	end_sq = ft_strchr(tok->input + tok->index, '\'');
	if (!end_sq)
	{
		generate_token(token, "Need simple quote at the end", 28);
		token->type = T_INVALID;
		return ;
	}
	size = end_sq - (tok->input + tok->index);
	generate_token(token, tok->input + tok->index, size);
	tok->index += size + 1;
}
