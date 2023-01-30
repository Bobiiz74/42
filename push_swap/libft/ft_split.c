/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:11:49 by rgodtsch          #+#    #+#             */
/*   Updated: 2022/10/21 15:22:20 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_add_word(const char *s, int i_s, size_t i_e)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = ft_calloc(sizeof(*dest), i_e + 1);
	if (!dest)
		return (NULL);
	while (i < i_e)
	{
		dest[i] = s[i_s];
		i_s++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}	

static int	ft_count_w(const char *s, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	size_t	i[3];
	size_t	index2;
	char	**dest;

	ft_bzero(i, sizeof(size_t) * 3);
	i[2] = ft_count_w(s, c);
	dest = ft_calloc(sizeof(*dest), i[2] + 1);
	if (!(dest) || s == NULL)
		return (NULL);
	while (i[0] < i[2])
	{
		while (s[i[1]] == c && s[i[1]])
			i[1]++;
		if (ft_strchr((s + i[1]), c) == NULL)
			index2 = ft_strlen(s) - i[1];
		else
			index2 = ft_strchr((s + i[1]), c) - (s + i[1]);
		dest[i[0]] = ft_add_word(s, i[1], index2);
		if (!dest[i[0]])
			return (NULL);
		i[1] = i[1] + index2 + 1;
		i[0]++;
	}
	dest[i[0]] = NULL;
	return (dest);
}
