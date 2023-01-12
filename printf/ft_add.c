/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:17:34 by rgodtsch          #+#    #+#             */
/*   Updated: 2022/11/18 16:47:33 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar_1(char str)
{
	ft_putchar_fd(str, 1);
	return (1);
}

size_t	ft_add_char(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar_fd(c, 1);
	return (1);
}

size_t	ft_add_str(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return ((ft_strlen(str)));
}

size_t	ft_add_num(va_list ap)
{
	int		n;
	size_t	len;

	n = va_arg(ap, int);
	len = (size_t)ft_nbrlen(n);
	ft_putnbr_fd(n, 1);
	return (len);
}

size_t	ft_add_unum(va_list ap)
{
	int		n;
	size_t	len;

	n = va_arg(ap, unsigned int);
	if (n == 0)
	{
		ft_putunnbr_fd(0, 1);
		return (1);
	}
	len = (size_t)ft_unnbrlen(n);
	ft_putunnbr_fd(n, 1);
	return (len);
}
