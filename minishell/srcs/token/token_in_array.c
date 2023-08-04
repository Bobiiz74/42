/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_in_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:01:09 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/03 18:01:10 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	**token_in_array(t_tokenizer *tok)
{
	t_token	**array;
	t_list	*lst;
	int		i;
	int		size;

	i = 0;
	size = ft_lstsize(tok->tokens);
	array = malloc(sizeof(t_token *) * (size + 1));
	if (!array)
		return (NULL);
	lst = tok->tokens;
	while (lst)
	{
		array[i++] = lst->content;
		lst = lst->next;
	}
	array[i] = NULL;
	return (array);
}
