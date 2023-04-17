/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:53:53 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/04/17 13:12:13 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//Parcours chaque bit du char c, si le bit == 1 SIGUSR1 est renvoyé à ft_write,
//sinon SIGUSR2.

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
		usleep(200);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 1)
		ft_putstr_error("Usage : ./client PID string\n");
	if (ac == 2)
		ft_putstr_error("Not enough arguments\n");
	pid = mini_atoi(av[1]);
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
		ft_putstr_error("Error\n");
	return (0);
}
