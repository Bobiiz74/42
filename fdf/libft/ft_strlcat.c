/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:12:26 by rgodtsch          #+#    #+#             */
/*   Updated: 2022/10/17 16:12:41 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	char	*p_src;

	j = 0;
	i = 0;
	p_src = (char *)src;
	while (i < dstsize)
	{
		if (dst[i] == 0)
			break ;
		if (i == dstsize - 1 && dst[i])
			return (dstsize + ft_strlen(src));
		++i;
	}
	i = ft_strlen(dst);
	while (i + j < dstsize - 1 && p_src[j] && 0 < dstsize)
	{
		dst[i + j] = p_src[j];
		++j;
	}
	dst[i + j] = 0;
	if (dstsize < i)
		return (dstsize + ft_strlen(src));
	return (i + ft_strlen(src));
}
