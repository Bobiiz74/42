/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:41:43 by rgodtsch          #+#    #+#             */
/*   Updated: 2022/11/16 17:14:29 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <strings.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putunnbr_fd(unsigned int n, int fd);
void				ft_putendl_fd(char *s, int fd);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
int					ft_nbrlen(int n);
int					ft_unnbrlen(unsigned int n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_lstsize(t_list *lst);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strstr(const char *haystack, const char *to_find);
char				*ft_strnstr(const char *haystack, \
					const char *needle, size_t len);
char				*ft_strcat(char *dest, const char *src);
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strrchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
					void (*del)(void *));

// PRINTF

int		ft_printf(const char *format, ...);
size_t	add_res(const char *str, int start, va_list ap);
size_t	ft_putchar_1(char str);
size_t	ft_add_char(va_list ap);
size_t	ft_add_str(va_list ap);
size_t	ft_add_num(va_list ap);
size_t	ft_add_unum(va_list ap);
size_t	ft_add_p(va_list ap);
size_t	ft_add_hex(va_list ap, char c);
void	ft_put_base(size_t nbr, char *base);
size_t	ft_print_hex(size_t nbr, char *base);
size_t	ft_nbr_len_base(size_t nbr, char *base);
size_t	ft_print_hex(size_t nbr, char *base);

// GNL

char	*get_next_line(int fd);
char	*gnl_read(int fd, char *stash);
char	*gnl_get_line(char *buffer);
char	*gnl_rm_old_line(char *buffer);
void	*ft_calloc(size_t nb_elem, size_t size_elem);
int		gnl_strchr(char *str);
char	*gnl_strjoin(char *line, char *buff);
size_t	ft_strlen(const char *str);
char	*ft_strndup(char *str, size_t end);
char	*gnl_remove_free(char *buffer);


#endif
