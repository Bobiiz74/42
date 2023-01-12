/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:00:54 by rgodtsch          #+#    #+#             */
/*   Updated: 2022/10/24 15:22:46 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dest;
	char	*ptr;

	i = 0;
	dest = (char *)dst;
	ptr = (char *)src;
	if (dest < ptr)
	{
		while (i != len)
		{
			dest[i] = ptr[i];
			i++;
		}
	}
	else if (dest > ptr)
	{
		while (len)
		{
			dest[len - 1] = ptr[len - 1];
			len--;
		}
	}
	return (dst);
}
