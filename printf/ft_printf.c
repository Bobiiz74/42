/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:02:46 by rgodtsch          #+#    #+#             */
/*   Updated: 2022/11/18 17:39:14 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		i;
	size_t		dest;

	i = 0;
	dest = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			dest += add_res(format, i, ap);
		}
		else
			dest += ft_putchar_1(format[i]);
		i++;
	}
	va_end(ap);
	return (dest);
}

size_t	add_res(const char *str, int start, va_list ap)
{
	size_t	add_dest;

	add_dest = 0;
	if (str[start] == '%')
		add_dest = ft_putchar_1(str[start]);
	else if (str[start] == 'c')
		add_dest = ft_add_char(ap);
	else if (str[start] == 's')
		add_dest = ft_add_str(ap);
	else if (str[start] == 'd' || str[start] == 'i')
		add_dest = ft_add_num(ap);
	else if (str[start] == 'u')
		add_dest = ft_add_unum(ap);
	else if (str[start] == 'x' || str[start] == 'X')
		add_dest = ft_add_hex(ap, str[start]);
	else if (str[start] == 'p')
		add_dest = ft_add_p(ap);
	else
		ft_putchar_fd(str[start], 1);
	return (add_dest);
}
