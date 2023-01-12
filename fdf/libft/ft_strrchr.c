/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:42:13 by rgodtsch          #+#    #+#             */
/*   Updated: 2022/10/23 13:51:20 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*cs;
	char	cc;

	i = 0;
	cs = (char *)s;
	cc = (char)c;
	while (cs[i] != 0)
		i++;
	while (cs[i] != cc && i != 0)
		i--;
	if (cs[i] == cc)
		return (&cs[i]);
	return (NULL);
}

/*int	main()
{
	char str[] = "Voir comment ca marche";
	printf ("expected : %s\n", strrchr(str, 'z'));
	printf ("result : %s\n", ft_strrchr(str, 'z'));
	return(0);
}*/
