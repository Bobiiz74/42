/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:07:13 by rgodtsch          #+#    #+#             */
/*   Updated: 2022/11/03 12:41:25 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;
	size_t	tmp_l;

	i = 0;
	if (s == NULL)
		return (NULL);
	tmp_l = ft_strlen(s);
	if (start > tmp_l)
		len = 0;
	else if (len >= ft_strlen(s + start))
		len = tmp_l - start;
	dest = ft_calloc(sizeof(*dest), len + 1);
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	return (dest);
}
