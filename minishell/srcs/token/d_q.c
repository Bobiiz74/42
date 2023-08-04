/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_q.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:13:18 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/03 18:02:07 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// check si var a un seul caractere sinon, renvoie 0;
// si var return (1) -> alors var == 1 et doit etre gerer a part;
static int	ft_size_var(t_tokenizer *tok, char **var_value)
{
	if (tok->input[tok->index] == '~')
	{
		*var_value = ft_strdup("$~");
		tok->index++;
		return (1);
	}
	if (tok->input[tok->index] == ' '
		|| tok->input[tok->index] == '\t')
	{
		*var_value = ft_strdup("$");
		tok->index++;
		return (1);
	}
	if (tok->input[tok->index] == '?')
	{
		*var_value = ft_itoa(tok->status);
		tok->index++;
		return (1);
	}
	return (0);
}

// on recupere la valeur de $ -> savoir si c un env ou pas;
// savoir si c'est la demande du status etc;
static char	*ft_var_mode(t_tokenizer *tok)
{
	char	*var_name;
	char	*var_value;
	int		size;

	tok->index += 1;
	size = token_var_len(tok);
	if (ft_size_var(tok, &var_value))
		return (var_value);
	var_name = ft_substr(tok->input, tok->index, size);
	tok->index += size;
	if (var_name)
	{
		var_value = get_env_var_value(var_name);
		if (var_value)
			var_value[0] = '\0';
		free(var_name);
		return (var_value);
	}
	var_value[0] = '\0';
	return (var_value);
}

// On recuperer la string si y a pas de VAR dedans;
static char	*mode_str(t_tokenizer *tok)
{
	char	*str;
	int		size;

	size = 0;
	while (tok->input[tok->index + size] != '$'
		&& tok->input[tok->index + size] != '"')
		size++;
	str = ft_substr(tok->input, tok->index, size);
	tok->index += size;
	return (str);
}

// enveler les DBLEQUOTE + check VAR -> "$PWD";
void	fill_token_dble(t_tokenizer *tok, t_token *token)
{
	char	*current;
	char	*old;
	int		already_check;
	char	*to_string;

	already_check = 0;
	current = NULL;
	old = NULL;
	while (tok->input[tok->index] != '"')
	{
		if (tok->input[tok->index] == '$')
			current = ft_var_mode(tok);
		else
			current = mode_str(tok);
		if (!already_check++)
			to_string = current;
		else
		{
			old = to_string;
			to_string = ft_strjoin(to_string, current);
			free(old);
		}
	}
	generate_token(token, to_string, ft_strlen(to_string));
	free(to_string);
}

// check du  DBLEQUOTE + 1 -> jusqu'a DBLEQUOTE final;
void	double_quote(t_tokenizer *tok, t_token *token)
{
	char	*end_dble;

	token->type = T_D_QUOTE;
	tok->index += 1;
	end_dble = ft_strchr(tok->input + tok->index, '"');
	if (!end_dble)
	{
		generate_token(token, "Need a double quote to end", 26);
		token->type = T_INVALID;
		return ;
	}
	fill_token_dble(tok, token);
	tok->index += 1;
}
