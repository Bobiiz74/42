/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:10:07 by rgodtsch          #+#    #+#             */
/*   Updated: 2022/12/08 16:41:02 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = gnl_read(fd, stash);
	if (!stash)
		return (NULL);
	line = gnl_get_line(stash);
	stash = gnl_rm_old_line(stash);
	return (line);
}

char	*gnl_read(int fd, char *stash)
{
	ssize_t	bytes_readed;
	char	*buffer;

	if (!stash)
		stash = (char *)ft_calloc(1, sizeof(char));
	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!stash || !buffer)
		return (NULL);
	bytes_readed = 1;
	while (bytes_readed > 0)
	{
		bytes_readed = read(fd, buffer, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bytes_readed] = 0;
		stash = gnl_strjoin(stash, buffer);
		if (gnl_strchr(buffer) != -1)
			break ;
	}
	free(buffer);
	return (stash);
}

char	*gnl_get_line(char *buffer)
{
	int		i;
	char	*str;

	if (!buffer[0])
		return (NULL);
	i = gnl_strchr(buffer);
	if (i == -1)
		i = ft_strlen(buffer);
	str = ft_strndup(buffer, i);
	if (!str)
		return (NULL);
	return (str);
}

char	*gnl_rm_old_line(char *buffer)
{
	char	*str;
	int		i;
	int		j;

	if (buffer == NULL)
	{
		return (gnl_remove_free(buffer));
	}
	i = gnl_strchr(buffer);
	if (i == -1)
		return (gnl_remove_free(buffer));
	str = (char *)ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!str)
		return (gnl_remove_free(buffer));
	j = 0;
	while (buffer[++i])
		str[j++] = buffer[i];
	str[j] = '\0';
	free(buffer);
	return (str);
}

char	*gnl_remove_free(char *buffer)
{
	free(buffer);
	return (NULL);
}
