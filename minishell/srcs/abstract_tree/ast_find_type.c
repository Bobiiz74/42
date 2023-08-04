/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_find_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 22:11:29 by ppotier           #+#    #+#             */
/*   Updated: 2023/07/25 17:43:17 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static const t_node_type	g_toktype_to_asttype[] = {[T_PIPE] = AST_PIPE};

int	ast_find_token(t_token_type type, t_token **token, int start, int size)
{
	int	pos;

	pos = 0;
	while (pos < size)
	{
		if (token[pos + start]->type == type)
			return (pos + start);
		pos++;
	}
	return (-1);
}

int	find_type(t_node *root, t_token **token, int start, int size)
{
	int							i;
	int							tok_pos;
	static const t_token_type	checked_types[] = {
		T_PIPE
	};

	i = -1;
	while (++i < 1)
	{
		tok_pos = ast_find_token(checked_types[i], token, start, size);
		if (tok_pos != -1)
		{
			root->type = g_toktype_to_asttype[checked_types[i]];
			return (tok_pos);
		}
	}
	return (-1);
}
