/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:45:41 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/06/07 16:48:13 by rgodtsch         ###   ########.fr       */
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
		ft_usleep(info->time_to_eat + 1);
	while (info->must_eat == -1)
		activity(info, philo);
	while (philo[i].eat_count != info->must_eat)
		activity(info, philo);
	return (NULL);
}

void	activity(t_info *info, t_philo *philo)
{
	if (philo->left_fork->taken == 1 && philo->right_fork->taken == 1)
	{
		philo->left_fork->taken = 0;
		pthread_mutex_lock(&philo->left_fork->mutex);
		pthread_mutex_lock(&info->write_mut);
		write_status("has taken a fork\n", philo, info);
		pthread_mutex_unlock(&info->write_mut);
		philo->right_fork->taken = 0;
		pthread_mutex_lock(&philo->right_fork->mutex);
		pthread_mutex_lock(&info->write_mut);
		write_status("has taken a fork\n", philo, info);
		pthread_mutex_unlock(&info->write_mut);
		pthread_mutex_lock(&info->write_mut);
		write_status("is eating\n", philo, info);
		philo->eat_count += 1;
		pthread_mutex_unlock(&info->write_mut);
		ft_usleep(info->time_to_eat);
		pthread_mutex_unlock(&philo->left_fork->mutex);
		pthread_mutex_unlock(&philo->right_fork->mutex);
		philo->left_fork->taken = 1;
		philo->right_fork->taken = 1;
		sleep_think(philo, info);
	}
	else
	{
		ft_usleep(info->time_to_eat);
		activity(info, philo);
	}
}

void	write_status(char *str, t_philo *philo, t_info *info)
{
	long int		time;

	time = -1;
	time = actual_time() - info->start_t;
	if (time >= 0 && time <= 2147483647)
	{
		printf("%ld ", time);
		printf("Philo %d %s", philo->id, str);
	}
}

void	sleep_think(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&info->write_mut);
	write_status("is sleeping\n", philo, info);
	pthread_mutex_unlock(&info->write_mut);
	ft_usleep(info->time_to_sleep);
	pthread_mutex_lock(&info->write_mut);
	write_status("is thinking\n", philo, info);
	pthread_mutex_unlock(&info->write_mut);
}

void	one_philo(int time_to_die)
{
	printf("0 Philo 1 has taken a fork\n");
	ft_usleep(time_to_die);
	printf("%d Philo 1 died because he is to dumb to eat with only one \
			fork :)\n", time_to_die);
	exit (1);
}
