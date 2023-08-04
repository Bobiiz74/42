/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:04:27 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/03 17:08:25 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_pipe(t_token **token)
{
	int	i;

	i = -1;
	while (token[++i])
	{
		if (token[i]->type == T_PIPE && !check_word_around(token, i))
		{
			ft_put_error("syntax error", "invalid |");
			return (0);
		}
	}
	return (1);
}

int	is_redir(t_token *token)
{
	if (token->type == T_REDIR_IN)
		return (1);
	else if (token->type == T_REDIR_OUT)
		return (1);
	else if (token->type == T_HEREDOC)
		return (1);
	else if (token->type == T_REDIR_APP)
		return (1);
	else
		return (0);
}

static int	check_redir_name(char *content)
{
	if (!content)
		return (0);
	if (content[0] == '<' || content[0] == '>')
		return (0);
	return (1);
}

static int	check_redir(t_token **token)
{
	int	i;

	i = -1;
	while (token[++i])
	{
		if (is_redir(token[i]) && !check_redir_name(token[i]->content))
		{
			ft_put_error("syntax error", "invalid redirection filename");
			return (0);
		}
	}
	return (1);
}

int	ft_check_syntax(t_token **token)
{
	int	i;

	if (token && !token[0])
		return (1);
	else if (!check_redir(token))
		return (3);
	else if (!check_pipe(token))
		return (3);
	else if (!check_bracket_num(token)
		|| !check_bracket_o(token) || !check_bracket_c(token))
		return (3);
	i = -1;
	while (token[++i])
	{
		if (token[i]->type == T_INVALID)
		{
			ft_put_error("syntax error", "unterminated quote");
			return (3);
		}
	}
	return (0);
}
