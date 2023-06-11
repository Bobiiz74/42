/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:45:41 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/06/11 18:24:24 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_philo(void *arg)
{
	t_philo	*philo;
	t_info	*info;
	int		i;
	int		id;

	philo = (t_philo *) arg;
	info = philo->info;
	id = philo->id;
	i = 0;
	if (id % 2 == 0)
		ft_usleep(info->time_to_eat / 10, info, philo);
	while (info->must_eat == -1)
	{

		if(info->stop == 1)
			activity(info, philo);
		else
			break ;
	}
	while (philo[i].eat_count != info->must_eat)
	{	
		if(info->stop == 0)
			break ;
		else
			activity(info, philo);
	}
	return (NULL);
}

void	activity(t_info *info, t_philo *philo)
{
	if (philo->left_fork->taken == 1 && philo->right_fork->taken == 1 && info->stop == 1)
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		philo->left_fork->taken = 0;
		write_status("has taken a fork\n", philo, info);
		pthread_mutex_lock(&philo->right_fork->mutex);
		philo->right_fork->taken = 0;
		write_status("has taken a fork\n", philo, info);
		write_status("is eating\n", philo, info);
		philo->eat_count += 1;
		philo->last_meal = actual_time();
		ft_usleep(info->time_to_eat, info, philo);	
		philo->left_fork->taken = 1;
		philo->right_fork->taken = 1;
		pthread_mutex_unlock(&philo->left_fork->mutex);
		pthread_mutex_unlock(&philo->right_fork->mutex);
		sleep_think(philo, info);
	}	
}

void	write_status(char *str, t_philo *philo, t_info *info)
{
	long int		time;

	time = -1;
	time = actual_time() - info->start_t;	
	if (time >= 0 && time <= 2147483647 && info->stop == 1)
	{
		pthread_mutex_lock(&info->write_mut);
		printf("%ld ", time);
		printf("Philo %d %s", philo->id, str);
		pthread_mutex_unlock(&info->write_mut);
	}
}

void	sleep_think(t_philo *philo, t_info *info)
{
	if(info->stop == 1)
	{
		write_status("is sleeping\n", philo, info);
		is_dead(info, philo);
		ft_usleep(info->time_to_sleep, info, philo);
		is_dead(info, philo);
		write_status("is thinking\n", philo, info);
	}
}

void	one_philo(int time_to_die)
{
	printf("0 Philo 1 has taken a fork\n");
	usleep(time_to_die * 1000);
	printf("%d Philo 1 died because he is\
to dumb to eat with only one fork :)\n", time_to_die);
	exit (1);
}
