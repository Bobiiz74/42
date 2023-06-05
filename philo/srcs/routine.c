/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:45:41 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/06/05 12:57:41 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_philo(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	//(void)info;
	int i;
	int id;
	philo = (t_philo *) arg;
	info = philo->info;
	
	id = philo->id;
	i = 0;
	
	if(id % 2 == 0)
		ft_usleep(info->time_to_eat + 1000);
	printf("routine philo id : %d\n", id);
	printf("left%p\n", philo[id - 1].left_fork);	
	printf("right%p\n", philo[id - 1].right_fork);
	while(info->must_eat == -1)
		activity(info, philo[id - 1]);

	while(i < info->must_eat)
	{
		activity(info, philo[id - 1]);
		i++;
	}
	return (NULL);
}

void	activity(t_info *info, t_philo philo)
{
	//printf("coucou1\n");
	//printf("id : %D\n", philo.id);
	//printf("%p\n", philo.left_fork);
	if(philo.left_fork->taken == 1)
	{
		//printf("coucou2\n");
		philo.left_fork->taken = 0;
		pthread_mutex_lock(&philo.left_fork->mutex);
		write_status("has taken a fork\n", philo, info);
	}
	if(philo.right_fork->taken == 1)
	{
		philo.right_fork->taken = 0;
		pthread_mutex_lock(&philo.right_fork->mutex);
		write_status("has taken a fork\n", philo, info);
	}
	else
	{
		pthread_mutex_unlock(&philo.left_fork->mutex);
		philo.left_fork->taken = 0;
		activity(info, philo);

	}
	if(philo.left_fork->taken == 0 && philo.right_fork->taken == 0)
	{
		write_status("is eating\n", philo, info);
		ft_usleep(info->time_to_eat);
		pthread_mutex_unlock(&philo.left_fork->mutex);
		pthread_mutex_unlock(&philo.right_fork->mutex);
		philo.left_fork->taken = 0;
		philo.right_fork->taken = 0;

	}
	

	write_status("jai fini de graille\n", philo, info);
	sleep_think(&philo, info);
}

void	write_status(char *str, t_philo philo, t_info *info)
{
	long int		time;

	time = -1;
	time = actual_time() - info->start_t;
	if (time >= 0 && time <= 2147483647)
	{
		printf("%ld ", time);
		printf("Philo %d %s", philo.id, str);
	}
}

void	sleep_think(t_philo *philo, t_info *info)
{
	write_status("is sleeping\n", *philo, info);
	ft_usleep(info->time_to_sleep);
	write_status("is thinking\n", *philo, info);
}
