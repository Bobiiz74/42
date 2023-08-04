/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:44:04 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/03 17:58:23 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_ndup(char *s, size_t n)
{
	size_t	len;
	size_t	i;
	char	*cp;

	if (!s)
		return (NULL);
	len = get_len(s);
	if (len > n)
		len = n;
	i = 0;
	cp = ft_calloc(sizeof(*cp), (len + 1));
	if (!cp)
		return (NULL);
	while (i < len)
	{
		*(cp + i) = *(s + i);
		i++;
	}
	*(cp + i) = '\0';
	return (cp);
}

char	*get_join(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*dest;
	size_t	i;

	i = 0;
	l1 = get_len(s1);
	l2 = get_len(s2);
	dest = ft_calloc(sizeof(*dest), (l1 + l2 + 1));
	if (!dest)
		return (NULL);
	while (i < l1)
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < l2)
	{
		dest[l1 + i] = s2[i];
		i++;
	}
	dest[l1 + l2] = '\0';
	return (dest);
}

int	get_next_c(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
		return (i);
	else
		return (0);
}

int	get_len(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
