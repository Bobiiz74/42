/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:27:05 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/05/11 17:49:48 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	if(argc == 5 || argc == 6)
		core_philo(ft_atoi(av[1]), ft_atoi(av[2]));
	else
		ft_putstr_fd("Error\n", 2);
		
}

int init_philo(int number_of_philosophers, int time_to_die)
{
	
}

int thrd_create( thrd_t *thread, thrd_start_t startFunction, void * data );
