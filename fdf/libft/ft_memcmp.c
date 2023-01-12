/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:23:07 by rgodtsch          #+#    #+#             */
/*   Updated: 2022/10/17 16:23:34 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*vs1;
	const char	*vs2;

	i = 0;
	vs1 = (const char *)s1;
	vs2 = (const char *)s2;
	while (i != n)
	{
		if ((unsigned char)vs1[i] != (unsigned char)vs2[i])
			return ((unsigned char)vs1[i] - (unsigned char)vs2[i]);
		i++;
	}
	return (0);
}
