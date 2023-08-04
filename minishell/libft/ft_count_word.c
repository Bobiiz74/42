/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_sep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:22:04 by ppotier           #+#    #+#             */
/*   Updated: 2023/03/09 14:06:12 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i] == c && s[i])
		i++;
	if (!s[i])
		return (word);
	while (s[i])
	{
		if (s[i] == c)
		{
			word++;
			while (s[i] && s[i] == c)
				i++;
		}
		else
			i++;
	}
	return (word + 1);
}
