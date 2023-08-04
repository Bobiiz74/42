/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:14:21 by ppotier           #+#    #+#             */
/*   Updated: 2023/01/12 12:14:24 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_un(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putnbr_fd((n) / 10, fd);
		ft_putnbr_fd((n) % 10, fd);
	}
	else
		ft_putchar_fd((n + '0'), fd);
}
