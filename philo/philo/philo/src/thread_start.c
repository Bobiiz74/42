/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomat <ktomat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:20:07 by ktomat            #+#    #+#             */
/*   Updated: 2023/06/19 10:54:27 by ktomat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	cycle_1(t_table *table)
{
	printf("0 ms philo [1] has taken a fork\n");
	ms_sleep(table->times->die_time);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		usleep(500);
	while (status_check(philo))
	{	
		eat(philo);
		if (status_check(philo) == 0)
			break ;
		sleep1(philo);
		if (status_check(philo) == 0)
			break ;
	}
	return (NULL);
}

int	thread_start(t_table *table)
{
	int	i;

	i = 0;
	table->times->start_time = get_actual_time();
	if (table->nbr_philo == 1)
	{
		cycle_1(table);
		return (0);
	}
	while (i < table->nbr_philo - 1)
	{
		table->philo[i].next_fork = &table->philo[i + 1].fork;
		i++;
	}
	table->philo[i].next_fork = &table->philo[0].fork;
	i = 0;
	while (i < table->nbr_philo)
	{
		if (pthread_create(&table->philo[i].thread, NULL,
				routine, &table->philo[i]) != 0)
			return (msg_error("Thread create fail"));
		i++;
	}
	return (0);
}
