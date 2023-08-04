/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:00:17 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/22 22:27:37 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			nb = (unsigned int)n * -1;
		}
		else
			nb = (unsigned int) n;
		if (nb >= 10)
		{
			ft_putnbr_fd((nb / 10), fd);
		}
		ft_putchar_fd(nb % 10 + 48, fd);
	}
}
