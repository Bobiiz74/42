/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:11:55 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/01/14 16:04:17 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gnl_strchr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*gnl_strjoin(char *line, char *buff)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	tlen;

	tlen = ft_strlen(line) + ft_strlen(buff) + 1;
	str = (char *)ft_calloc(tlen, sizeof(char));
	if (!str)
		free(line);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	while (buff[j])
	{
		str[i++] = buff[j++];
	}
	free(line);
	str[i] = '\0';
	return (str);
}

char	*ft_strndup(char *buffer, size_t end)
{
	char	*str;
	size_t	i;

	str = (char *)ft_calloc(end + 2, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i <= end && buffer[i])
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
