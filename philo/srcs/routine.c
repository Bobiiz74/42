/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:45:41 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/06/30 17:03:54 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_philo(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *) arg;
	info = philo->info;
	if (philo->id % 2 == 0)
		ft_usleep(info->time_to_eat / 10, info, philo);
	if (info->must_eat == -1)
	{
		while (is_dead(info, philo) == 1)
		{
			activity(info, philo);
		}
	}
	else if (philo->eat_count != info->must_eat)
	{		
		while (is_dead(info, philo) == 1)
		{
			activity(info, philo);
		}
	}	
	return (NULL);
}

void	activity(t_info *info, t_philo *philo)
{
	if (is_dead(info, philo) == 1)
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		pthread_mutex_lock(&philo->right_fork->mutex);
		write_status("has taken a fork\n", philo, info);
		write_status("has taken a fork\n", philo, info);
		write_status("is eating\n", philo, info);
		philo->eat_count += 1;
		pthread_mutex_lock(&info->time);
		philo->last_meal = actual_time();
		pthread_mutex_unlock(&info->time);
		ft_usleep(info->time_to_eat, info, philo);
		pthread_mutex_unlock(&philo->left_fork->mutex);
		pthread_mutex_unlock(&philo->right_fork->mutex);
		sleep_think(philo, info);
	}
	else
		return ;
}

void	write_status(char *str, t_philo *philo, t_info *info)
{
	long int		time;

	time = -1;
	time = actual_time() - info->start_t;
	is_dead(info, philo);
	if (time >= 0 && time <= 2147483647)
	{
		pthread_mutex_lock(&info->write_mut);
		printf("%ld ", time);
		printf("Philo %d %s", philo->id, str);
		pthread_mutex_unlock(&info->write_mut);
	}
}

void	sleep_think(t_philo *philo, t_info *info)
{
	if (is_dead(info, philo) == 1)
	{
		write_status("is sleeping\n", philo, info);
		ft_usleep(info->time_to_sleep, info, philo);
		write_status("is thinking\n", philo, info);
		if (is_dead(info, philo) == 1)
			pthread_mutex_unlock(&info->write_mut);
	}
}

void	one_philo(int time_to_die)
{
	printf("0 Philo 1 has taken a fork\n");
	usleep(time_to_die * 1000);
	printf("%d Philo 1 died because he is\
	to dumb to eat with only one fork :)\n", time_to_die);
}
