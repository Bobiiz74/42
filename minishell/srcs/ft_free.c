/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:51:56 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/03 17:59:21 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	token_void(void *tok)
{
	(void) tok;
}

void	tokenizer_destroy(t_tokenizer *tok)
{
	if (!tok)
		return ;
	ft_lstclear(&tok->tokens, token_void);
	free(tok->input);
	free(tok);
}

int	free_args(char **str)
{
	int	i;

	if (!str)
		return (1);
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return (1);
}

void	destroy_token(t_token *token)
{
	if (!token)
		return ;
	free(token->content);
	free(token);
}

void	tokens_destroy(t_token **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = -1;
	while (tokens[++i])
		destroy_token(tokens[i]);
	free(tokens);
}
