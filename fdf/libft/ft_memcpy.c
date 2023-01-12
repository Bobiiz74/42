/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:07:54 by rgodtsch          #+#    #+#             */
/*   Updated: 2022/10/17 16:10:47 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*ptr;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dest = (char *)dst;
	ptr = (char *)src;
	while (i != n)
	{
		dest[i] = ptr[i];
		i++;
	}
	return (dest);
}
