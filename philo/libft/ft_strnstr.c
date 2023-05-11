/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:02:30 by rgodtsch          #+#    #+#             */
/*   Updated: 2022/10/17 16:24:01 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*h;

	h = (char *)haystack;
	i = 0;
	if (needle[0] == '\0')
		return (h);
	while (h[i] && ft_strlen(needle) + i - 1 < len)
	{
		if (h[i] == needle[0])
		{
			if (ft_strncmp((h + i), needle, ft_strlen(needle)) == 0)
				return (h + i);
		}
		i++;
	}
	return (NULL);
}

/*int main()
{
	char	*res = ft_strnstr("bonjour","j", 3);
	char *vraires = strnstr("bonjour","j", 3);
	printf("%s\n", res);
	printf("%s\n", vraires);
	return (0);
}*/
