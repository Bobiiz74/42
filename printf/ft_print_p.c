/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:27:31 by rgodtsch          #+#    #+#             */
/*   Updated: 2022/11/16 18:32:56 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_add_p(va_list ap)
{
	size_t	count;
	size_t	p;
	char	*base;

	count = 2;
	base = "0123456789abcdef";
	p = va_arg(ap, size_t);
	ft_putstr_fd("0x", 1);
	if (p == 0)
	{
		count += 1;
		ft_putstr_fd("0", 1);
		return (count);
	}
	ft_put_base(p, base);
	count += ft_nbr_len_base(p, base);
	return (count);
}
