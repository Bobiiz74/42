/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomat <ktomat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:32:24 by ktomat            #+#    #+#             */
/*   Updated: 2023/06/19 10:53:51 by ktomat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(char *str, t_philo *philo)
{
	if (status_check(philo))
	{
		pthread_mutex_lock(&philo->table->print);
		if (status_check(philo))
		{
			printf("%llu ms philo [%d] %s\n",
				get_time_pass(philo->times->start_time, get_actual_time()),
				philo->id, str);
		}
		pthread_mutex_unlock(&philo->table->print);
	}
}

int	status_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->status1);
	if (philo->table->status == 1)
	{
		pthread_mutex_unlock(&philo->table->status1);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&philo->table->status1);
		return (0);
	}
}

void	eat(t_philo *philo)
{
	if (status_check(philo))
	{
		pthread_mutex_lock(&philo->fork);
		print("has taken a fork", philo);
		pthread_mutex_lock(philo->next_fork);
		print("has taken a fork", philo);
		print("is eating", philo);
		ms_sleep(philo->times->eat_time);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->next_fork);
		pthread_mutex_lock(&philo->lst_meal);
		philo->time_last_meal = get_actual_time();
		pthread_mutex_unlock(&philo->lst_meal);
		pthread_mutex_lock(&philo->meal);
		philo->nbr_of_meal += 1;
		pthread_mutex_unlock(&philo->meal);
	}
}

void	sleep1(t_philo *philo)
{
	if (status_check(philo))
	{
		print("is sleeping", philo);
		ms_sleep(philo->times->sleep_time);
		think(philo);
	}
}

void	think(t_philo *philo)
{
	if (status_check(philo))
	{
		print("is thinking", philo);
	}
}
