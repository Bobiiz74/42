/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:32:24 by robin             #+#    #+#             */
/*   Updated: 2023/07/05 14:11:46 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(char *str, t_philo *philo)
{
	if (status_check(philo))
	{
		pthread_mutex_lock(&philo->info->write);
		if (status_check(philo))
		{
			printf("%llu philo %d %s\n",
				get_time_pass(philo->times->start_time, get_actual_time()),
				philo->id, str);
		}
		pthread_mutex_unlock(&philo->info->write);
	}
}

int	status_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->status1);
	if (philo->info->status == 1)
	{
		pthread_mutex_unlock(&philo->info->status1);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&philo->info->status1);
		return (0);
	}
}

void	eat(t_philo *philo)
{
	if (status_check(philo))
	{
		pthread_mutex_lock(&philo->fork);
		write_status("has taken a fork", philo);
		pthread_mutex_lock(philo->next_fork);
		write_status("has taken a fork", philo);
		write_status("is eating", philo);
		ft_usleep(philo->times->eat_time);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->next_fork);
		pthread_mutex_lock(&philo->last_meal);
		philo->time_last_meal = get_actual_time();
		pthread_mutex_unlock(&philo->last_meal);
		pthread_mutex_lock(&philo->meal);
		philo->nbr_of_meal += 1;
		pthread_mutex_unlock(&philo->meal);
	}
}

void	sleep1(t_philo *philo)
{
	if (status_check(philo))
	{
		write_status("is sleeping", philo);
		ft_usleep(philo->times->sleep_time);
		think(philo);
	}
}

void	think(t_philo *philo)
{
	if (status_check(philo))
	{
		write_status("is thinking", philo);
	}
}
