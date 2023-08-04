/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 22:21:22 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/03 18:01:00 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// check si c'est autre chose que des simple, double ou space; puis
// genere le token approprié;
static void	normal_mode(t_tokenizer *tok, t_token *token)
{
	if (tok->input[tok->index] == '(' || tok->input[tok->index] == ')')
		token_bracket(tok, token);
	else if (tok->input[tok->index] == '|')
		token_pipe(tok, token);
	else if (tok->input[tok->index] == '&')
		token->type = T_INVALID;
	else if (tok->input[tok->index] == '<')
		token_redir_i(tok, token);
	else if (tok->input[tok->index] == '>')
		token_redir_o(tok, token);
	else if (tok->input[tok->index] == '$')
		token_var(tok, token);
	else if (tok->input[tok->index] == '~')
		token_tilde(tok, token);
	else
		token_word(tok, token);
}

// check chaque token, si sapce, dble quote, simple, ou que des mot;
t_token	*ft_token_next_token(t_tokenizer *tok)
{
	t_token	*token;
	t_list	*new_elem;

	if (!tok->input[tok->index])
		return (NULL);
	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->rmv = 0;
	if (tok->input[tok->index] == ' ' || tok->input[tok->index] == '\t')
		ft_space(tok, token);
	else if (tok->input[tok->index] == '\'')
		simple_quote(tok, token);
	else if (tok->input[tok->index] == '"')
		double_quote(tok, token);
	else
		normal_mode(tok, token);
	new_elem = ft_lstnew(token);
	if (!new_elem)
		return (NULL);
	ft_lstadd_back(&tok->tokens, new_elem);
	return (token);
}

// initialisation, allocation de memoire
t_tokenizer	*toker_init(char *input, int status)
{
	t_tokenizer	*tok;
	int			i;

	i = 0;
	tok = malloc(sizeof(t_tokenizer));
	if (!tok)
		return (NULL);
	tok->tokens = NULL;
	while (input[i] == ' ' || input[i] == '\t')
		i++;
	tok->input = ft_strdup(input + i);
	tok->status = status;
	tok->index = 0;
	return (tok);
}

// parsing mot par mot
t_token	**token_parse(t_tokenizer *tok)
{
	t_token	*token;

	token = ft_token_next_token(tok);
	while (token)
		token = ft_token_next_token(tok);
	return (token_in_array(tok));
}

/*initialisation, parsing, tout ranger dans une struct*/
t_token	**tokenizer_input(char *input, int status)
{
	t_tokenizer	*tok;
	t_token		**token;
	int			size;

	tok = toker_init(input, status);
	token = token_parse(tok);
	to_word(token);
	size = token_size(token);
	token = agregate_spaces(token, size);
	remove_useless(token);
	size = token_size(token);
	agregate_redir(&token);
	tokenizer_destroy(tok);
	free(input);
	return (token);
}
