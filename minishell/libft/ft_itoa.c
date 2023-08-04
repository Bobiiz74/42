/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 13:51:33 by ppotier           #+#    #+#             */
/*   Updated: 2023/01/12 14:23:10 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		taille;
	int		sign;
	char	*dest;

	taille = ft_nbrlen(n);
	if (n < 0)
		sign = -1;
	else
		sign = 1;
	dest = ft_calloc(sizeof(*dest), (taille + 1));
	if (!dest)
		return (NULL);
	dest[taille] = '\0';
	while (taille)
	{
		dest[--taille] = (n % 10) * sign + '0';
		n = n / 10;
	}
	if (sign == -1)
		dest[taille] = '-';
	return (dest);
}
