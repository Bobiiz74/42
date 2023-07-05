/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:42:37 by robin             #+#    #+#             */
/*   Updated: 2023/07/05 14:29:39 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nbr_philo)
	{
		pthread_mutex_lock(&info->philo[i].last_meal);
		if ((get_actual_time() - info->philo[i].time_last_meal)
			>= info->times->die_time)
		{
			pthread_mutex_lock(&info->status1);
			info->status = 0;
			pthread_mutex_unlock(&info->status1);
			pthread_mutex_lock(&info->write);
			printf("%llu philo %d is dead\n",
				get_time_pass(info->times->start_time, get_actual_time()),
				info->philo->id);
			pthread_mutex_unlock(&info->write);
			pthread_mutex_unlock(&info->philo[i].last_meal);
			return (-1);
		}
		pthread_mutex_unlock(&info->philo[i].last_meal);
		i++;
	}
	return (0);
}

int	check_meal(t_info *info)
{
	int	i;

	i = 0;
	if (info->times->nbr_of_meal_needed != -1)
	{
		while (i < info->nbr_philo)
		{
			pthread_mutex_lock(&info->philo[i].meal);
			if (info->philo[i].nbr_of_meal < info->times->nbr_of_meal_needed)
			{
				pthread_mutex_unlock(&info->philo[i].meal);
				return (0);
			}
			pthread_mutex_unlock(&info->philo[i].meal);
			i++;
		}
		pthread_mutex_lock(&info->status1);
			info->status = 0;
		printf("All philo eat %d times\n", info->times->nbr_of_meal_needed);
		pthread_mutex_unlock(&info->status1);
		return (-1);
	}
	return (0);
}
