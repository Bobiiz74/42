/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:11:55 by rgodtsch          #+#    #+#             */
/*   Updated: 2022/12/07 18:12:00 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nb_elem, size_t size_elem)
{
	void			*ptr;
	size_t			i;
	unsigned char	c;

	ptr = malloc(nb_elem * size_elem);
	if (!ptr)
		return (NULL);
	i = 0;
	c = '\0';
	while (i < (nb_elem * size_elem))
	{
		((char *)ptr)[i] = c;
		i++;
	}
	return (ptr);
}

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

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
