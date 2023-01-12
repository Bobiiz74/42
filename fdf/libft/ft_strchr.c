/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:01:04 by rgodtsch          #+#    #+#             */
/*   Updated: 2022/10/23 13:34:50 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cs;
	char	cc;

	cs = (char *)s;
	cc = (char)c;
	while (*cs != 0 && *cs != cc)
		cs++;
	if (*cs == cc)
		return (cs);
	else
		return (NULL);
}
