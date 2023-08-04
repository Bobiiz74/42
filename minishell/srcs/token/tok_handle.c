/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:58:38 by ppotier           #+#    #+#             */
/*   Updated: 2023/07/27 14:25:38 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// genere le token bracket;
void	token_bracket(t_tokenizer *tok, t_token *token)
{
	if (tok->input[tok->index] == '(')
	{
		token->type = T_BRACKET_OPN;
		generate_token(token, "(", 1);
	}
	if (tok->input[tok->index] == ')')
	{
		token->type = T_BRACKET_CLSE;
		generate_token(token, ")", 1);
	}
	tok->index += 1;
}

// genere le token PIPE, et si double pipe -> invalid;
void	token_pipe(t_tokenizer *tok, t_token *token)
{
	token->type = T_PIPE;
	generate_token(token, "|", 1);
	tok->index += 1;
}

// token redir in ou heredoc;
void	token_redir_i(t_tokenizer *tok, t_token *token)
{
	if (tok->input[tok->index + 1] == '<')
	{
		token->type = T_HEREDOC;
		generate_token(token, "<<", 2);
		tok->index += 2;
	}
	if (tok->input[tok->index] == '<')
	{
		token->type = T_REDIR_IN;
		generate_token(token, "<", 1);
		tok->index += 1;
	}
}

// genere token redir out, ou redirr app;
void	token_redir_o(t_tokenizer *tok, t_token *token)
{
	if (tok->input[tok->index + 1] == '>')
	{
		token->type = T_REDIR_APP;
		generate_token(token, ">>", 2);
		tok->index += 2;
	}
	if (tok->input[tok->index] == '>')
	{
		token->type = T_REDIR_OUT;
		generate_token(token, ">", 1);
		tok->index += 1;
	}
}

// si "~" print HOME; else token word;
void	token_tilde(t_tokenizer *tok, t_token *token)
{
	char	*value;

	if (tok->input[tok->index + 1] == ' '
		|| tok->input[tok->index + 1] == '\t'
		|| tok->input[tok->index + 1] == '/'
		|| tok->input[tok->index + 1] == '\0')
	{
		token->type = T_WORD;
		tok->index++;
		value = get_env_var_value("HOME");
		if (value)
			generate_token(token, value, ft_strlen(value));
		else
			generate_token(token, "~", 1);
		free(value);
	}
	else
		token_word(tok, token);
}
