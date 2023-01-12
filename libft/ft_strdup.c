/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:03:47 by rgodtsch          #+#    #+#             */
/*   Updated: 2022/11/05 17:25:00 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*cp;

	len = ft_strlen(s1);
	i = 0;
	cp = ft_calloc(sizeof(*cp), (len + 1));
	if (!cp)
		return (NULL);
	while (*(s1 + i) != 0)
	{
		*(cp + i) = *(s1 + i);
		i++;
	}
	return (cp);
}
