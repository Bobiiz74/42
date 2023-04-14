/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:21:51 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/04/14 14:27:10 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//Fct appellée a chaque signal, si 8bit dans i -> 1char, 
//si SIGUSR1 -> modifie valeur de i (1 bit vers la gauche) pour réassembler les char

void	ft_write(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar(i);
		bit = 0;
		i = 0;
	}
}

int main(int ac, char **av)
{
	(void) av;
	int pid;

	if(ac != 1)
	{
		ft_putstr("Error\n");
		return(1);
	}
	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	while(ac == 1)
	{
		signal(SIGUSR1, ft_write);
		signal(SIGUSR2, ft_write);
		pause();
	}
	return (0);
}
