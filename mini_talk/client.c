/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:53:53 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/04/06 17:17:47 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
		bit++;
	}
}

int main(int ac, char **av)
{
	int pid;
	int i;
	
	if (ac == 1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	pid = mini_atoi(av[1]);	
	i = 0;
	if (ac == 3)
	{
		while (av[2][i] != '\0')
		{
			ft_send(pid, av[2][i]);
			i++;
		}
		ft_send(pid, '\n');
	}
	else
	{
		ft_putstr("Error\n");
		return (1);
	}
	return(0);
}