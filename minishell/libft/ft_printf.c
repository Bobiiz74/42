/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:25:26 by ppotier           #+#    #+#             */
/*   Updated: 2023/01/12 11:53:34 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	dest;
	va_list	ap;

	i = 0;
	dest = 0;
	va_start (ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			dest = dest + ft_format(format, i, ap);
		}
		else
			dest = dest + ft_putchar_l(format[i]);
		i++;
	}
	va_end (ap);
	return (dest);
}

size_t	ft_format(const char *str, size_t start, va_list ap)
{
	size_t	res;

	res = 0;
	if (str[start] == '%')
		res = ft_putchar_l(str[start]);
	else if (str[start] == 'c')
		res = ft_add_char(ap);
	else if (str[start] == 's')
		res = ft_add_str(ap);
	else if (str[start] == 'p')
		res = ft_printp(ap);
	else if (str[start] == 'd' || str[start] == 'i')
		res = ft_putnbr_num(ap);
	else if (str[start] == 'u')
		res = ft_base_num(ap);
	else if (str[start] == 'x' || str[start] == 'X')
		res = ft_hex(ap, str[start]);
	return (res);
}
