/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomat <ktomat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:42:37 by ktomat            #+#    #+#             */
/*   Updated: 2023/06/14 10:47:55 by ktomat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_checker(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_mutex_lock(&table->philo[i].lst_meal);
		if ((get_actual_time() - table->philo[i].time_last_meal)
			>= table->times->die_time)
		{
			pthread_mutex_lock(&table->status1);
			table->status = 0;
			pthread_mutex_unlock(&table->status1);
			pthread_mutex_lock(&table->print);
			printf("%llu ms philo [%d] is dead\n",
				get_time_pass(table->times->start_time, get_actual_time()),
				table->philo->id);
			pthread_mutex_unlock(&table->print);
			pthread_mutex_unlock(&table->philo[i].lst_meal);
			return (-1);
		}
		pthread_mutex_unlock(&table->philo[i].lst_meal);
		i++;
	}
	return (0);
}

int	meal_checker(t_table *table)
{
	int	i;

	i = 0;
	if (table->times->nbr_of_meal_needed != -1)
	{
		while (i < table->nbr_philo)
		{
			pthread_mutex_lock(&table->philo[i].meal);
			if (table->philo[i].nbr_of_meal < table->times->nbr_of_meal_needed)
			{
				pthread_mutex_unlock(&table->philo[i].meal);
				return (0);
			}
			pthread_mutex_unlock(&table->philo[i].meal);
			i++;
		}
		pthread_mutex_lock(&table->status1);
			table->status = 0;
		printf("All philo have eat\n");
		pthread_mutex_unlock(&table->status1);
		return (-1);
	}
	return (0);
}
