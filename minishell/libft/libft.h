/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:50:13 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/25 12:14:29 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strchr(char *str, int c);
size_t		ft_strlen(const char *s);
int			strlen_until(const char *string, const char *charset);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strrchr(char *str, int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putendl_fd(char *s, int fd);
char		*ft_strjoin(char const *s1, char const *s2);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_itoa(int n);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(const char *s, char c);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int			strlen_until(const char *string, const char *charset);
int			max(int a, int b);
// ft_printf
int			ft_printf(const char *input, ...);
size_t		ft_putnbr_num(va_list ap);
size_t		ft_add_str(va_list ap);
size_t		ft_add_char(va_list ap);
size_t		ft_putchar_l(char str);
size_t		ft_format(const char *str, size_t start, va_list ap);
size_t		ft_base_num(va_list ap);
size_t		ft_print_hex(size_t nbr, char *base);
size_t		ft_hex(va_list ap, char c);
void		ft_put_base(size_t nbr, char *base);
size_t		ft_base_len(size_t nbr, char *base);
size_t		ft_printp(va_list ap);
int			ft_nbrlen(int n);
int			ft_nbrlen_un(unsigned int n);
void		ft_putnbr_un(unsigned int n, int fd);
// GNL
int			ft_count_word(char *s, char c);
char		*get_next_line(int fd);
char		*update_buff(int fd, char *rest);
char		*update_nextl(char *buff);
char		*get_res_line(char *buff);
char		*get_transf(char *s1, char *rest);
char		*get_join(char *s1, char *s2);
char		*get_ndup(char *s, size_t n);
int			get_next_c(char *s, char c);
int			get_len(char *s);
int			ft_is_sign(char c);

#endif