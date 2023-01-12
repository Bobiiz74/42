/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:06:34 by rgodtsch          #+#    #+#             */
/*   Updated: 2022/11/18 17:16:07 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunnbr_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putnbr_fd((n) / 10, fd);
		ft_putnbr_fd((n) % 10, fd);
	}
	else
		ft_putchar_fd((n + '0'), fd);
}
