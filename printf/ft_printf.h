/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:01:58 by rgodtsch          #+#    #+#             */
/*   Updated: 2022/11/18 16:59:28 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

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

#endif
