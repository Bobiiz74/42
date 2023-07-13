/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:20:07 by robin             #+#    #+#             */
/*   Updated: 2023/07/13 22:58:06 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_philo(t_info *info)
{
	printf("0 philo 1 has taken a fork\n");
	ft_usleep(info->times->die_time);
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

int	thread_start(t_info *info)
{
	int	i;

	i = 0;
	info->times->start_time = get_actual_time();
	if (info->nbr_philo == 1)
	{
		one_philo(info);
		return (0);
	}
	while (i < info->nbr_philo - 1)
	{
		info->philo[i].next_fork = &info->philo[i + 1].fork;
		i++;
	}
	info->philo[i].next_fork = &info->philo[0].fork;
	i = 0;
	while (i < info->nbr_philo)
	{
		if (pthread_create(&info->philo[i].thread, NULL,
				routine, &info->philo[i]) != 0)
			return (print_error("Thread create fail"));
		i++;
	}
	return (0);
}
