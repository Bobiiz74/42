/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:44:02 by ppotier           #+#    #+#             */
/*   Updated: 2023/03/15 11:30:22 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0)
		return (NULL);
	rest = update_buff(fd, rest);
	if (!rest)
	{
		free (rest);
		return (NULL);
	}
	line = get_res_line(rest);
	rest = update_nextl(rest);
	return (line);
}

char	*update_buff(int fd, char *rest)
{
	int		count;
	int		flag;
	char	sol[BUFFER_SIZE + 1];

	if (!rest)
		rest = ft_calloc(sizeof(*rest), 1);
	if (!rest)
		return (NULL);
	count = 1;
	flag = get_next_c(rest, '\n');
	while (count > 0 && !flag)
	{
		count = read(fd, sol, BUFFER_SIZE);
		if (count == -1)
		{
			free(rest);
			return (NULL);
		}
		sol[count] = '\0';
		rest = get_transf(sol, rest);
		if (!rest)
			return (NULL);
		flag = get_next_c(rest, '\n');
	}
	return (rest);
}

char	*get_transf(char *s1, char *rest)
{
	char	*tmp;

	tmp = get_join(rest, s1);
	free(rest);
	if (!tmp)
		return (NULL);
	return (tmp);
}

char	*get_res_line(char *buff)
{
	char	*str;
	int		ind;

	if (buff[0] == '\0')
		return (NULL);
	ind = 0;
	while (buff[ind] != '\0' && buff[ind] != '\n')
		ind++;
	str = get_ndup(buff, ind + 1);
	return (str);
}

char	*update_nextl(char *buff)
{
	char	*tmp;
	int		ind;
	int		i;

	ind = 0;
	while (buff[ind] != '\0' && buff[ind] != '\n')
		ind++;
	if (buff[ind] == '\0')
	{
		free(buff);
		return (NULL);
	}
	tmp = ft_calloc(sizeof(*tmp), get_len(buff) - ind + 1);
	i = 0;
	while (buff[++ind] != '\0')
	{
		tmp[i] = buff[ind];
		i++;
	}
	free(buff);
	return (tmp);
}
