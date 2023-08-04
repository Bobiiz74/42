/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:32:24 by ppotier           #+#    #+#             */
/*   Updated: 2023/07/28 16:01:07 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	token_var_len(t_tokenizer *tok)
{
	int	size;

	size = 0;
	if (tok->input[tok->index] && (!ft_isalpha(tok->input[tok->index]))
		&& tok->input[tok->index] != '_')
		return (1);
	while (tok->input[tok->index + size] == '_'
		|| ft_isalnum(tok->input[tok->index + size]))
		size++;
	return (size);
}

static int	size_one(t_tokenizer *tok, t_token *token)
{
	char	*str_status;

	if (tok->input[tok->index] == '~')
	{
		generate_token(token, "$~", 2);
		tok->index++;
		return (1);
	}
	else if (tok->input[tok->index] == ' '
		|| tok->input[tok->index] == '\t' || !tok->input[tok->index])
	{
		generate_token(token, "$", 1);
		return (1);
	}
	else if (tok->input[tok->index] == '?')
	{
		str_status = ft_itoa(tok->status);
		generate_token(token, str_status, ft_strlen(str_status));
		free(str_status);
		tok->index++;
		return (1);
	}
	return (0);
}

static void	var_is_empty(t_tokenizer *tok, t_token *token, int *size)
{
	generate_token(token, "", 0);
	tok->index += *size;
	token->rmv = 1;
}

void	token_var(t_tokenizer *tok, t_token *token)
{
	int		size_input;
	char	*var_name;
	char	*var_value;

	var_value = NULL;
	token->type = T_VAR;
	tok->index++;
	size_input = token_var_len(tok);
	if (size_one(tok, token))
		return ;
	var_name = ft_substr(tok->input, tok->index, size_input);
	if (var_name)
	{
		var_value = ms_getenv(var_name);
		if (!var_value)
		{
			free(var_name);
			return (var_is_empty(tok, token, &size_input));
		}
		generate_token(token, var_value + size_input + 1,
			ft_strlen(var_value + size_input + 1));
		free(var_name);
		free(var_value);
	}
	tok->index += size_input;
}
