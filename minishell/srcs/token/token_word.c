/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:03:00 by ppotier           #+#    #+#             */
/*   Updated: 2023/07/14 12:04:18 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// check si ce sont des special charac;
static int	token_chara(char c)
{
	int		i;
	char	*special_chars;

	special_chars = "()|$\'\"<>& \t";
	i = -1;
	while (special_chars[++i])
	{
		if (special_chars[i] == c)
			return (0);
	}
	return (1);
}

static int	word_size(t_tokenizer *tok, t_token *token)
{
	int	size;

	size = -1;
	while (tok->input[tok->index + ++size])
	{
		if (tok->input[tok->index + size] == '*')
			token->type = T_WILDCARD;
		if (!token_chara(tok->input[tok->index + size]))
			break ;
	}
	return (size);
}

// genere le T_WORD par rapport a sa size;
void	token_word(t_tokenizer *tok, t_token *token)
{
	int	size;

	token->type = T_WORD;
	size = word_size(tok, token);
	generate_token(token, tok->input + tok->index, size);
	tok->index += size;
}
