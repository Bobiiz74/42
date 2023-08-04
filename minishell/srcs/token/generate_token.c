/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:02:03 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/03 17:02:04 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	generate_token(t_token *token, char *src, int size)
{
	token->content = malloc(sizeof(char) * (size + 1));
	if (!token->content)
		return ;
	ft_memcpy(token->content, src, size);
	token->content[size] = '\0';
}
