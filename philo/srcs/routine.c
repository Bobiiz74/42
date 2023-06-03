/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:45:41 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/06/03 17:40:29 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_philo(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	//int i;
	int id;
	philo = (t_philo *) arg;
	info = philo->info;
	
	id = philo->id;
	//printf("routine philo id : %d\n", id);
	//i = 1;
	
	if(philo->id % 2 == 0)
		ft_usleep(info->time_to_eat / 10);
	//printf("1left%p\n", philo[id].left_fork);
	//while(i <= info->number_of_philosophers)
	//{
		//printf("left%p\n", philo[i].left_fork);
	activity(info, philo[id]);
	//	i++;
//	}	
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
		pthread_mutex_lock(&philo.left_fork->mutex);
		write_status("has taken a fork\n", philo, info);
		philo.left_fork->taken = 0;
	}
	else
		ft_usleep(2000);
	if(philo.right_fork->taken == 1)
	{
		pthread_mutex_lock(&philo.right_fork->mutex);
		write_status("has taken a fork\n", philo, info);
		philo.right_fork->taken = 0;
	}
	else
		ft_usleep(2000);
	if(philo.left_fork->taken == 0 && philo.right_fork->taken == 0)
	{
		write_status("is eating\n", philo, info);
		ft_usleep(info->time_to_eat);
		pthread_mutex_unlock(&philo.left_fork->mutex);
		pthread_mutex_unlock(&philo.right_fork->mutex);
		philo.left_fork->taken = 0;
		philo.right_fork->taken = 0;
	}
	printf("jai fini activity\n");
	//sleep_think(&philo, info);
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
