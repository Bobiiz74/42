/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:13:49 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/25 12:44:13 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	i;
	char	*sub;

	i = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s);
	if (start > j)
		len = 0;
	else if (len >= ft_strlen(s + start))
		len = j - start;
	sub = ft_calloc(sizeof(*sub), len + 1);
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}
