/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:12:31 by rgodtsch          #+#    #+#             */
/*   Updated: 2022/12/08 16:41:07 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*gnl_read(int fd, char *stash);
char	*gnl_get_line(char *buffer);
char	*gnl_rm_old_line(char *buffer);
void	*ft_calloc(size_t nb_elem, size_t size_elem);
int		gnl_strchr(char *str);
char	*gnl_strjoin(char *line, char *buff);
size_t	ft_strlen(char *str);
char	*ft_strndup(char *str, size_t end);
char	*gnl_remove_free(char *buffer);

#endif
