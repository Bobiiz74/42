/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:24:25 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/06/30 16:45:00 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_struct_philo(t_info *info)
{
	t_philo	*philo;
	int		nb_philo;
	int		i;

	nb_philo = info->number_of_philosophers;
	philo = malloc(sizeof(t_philo) * nb_philo);
	if (!philo)
		return (NULL);
	init_philo(info, philo);
	i = 0;
	while (i < nb_philo)
	{	
		if (pthread_create(&philo[i].thread_id, NULL, &routine_philo, \
					&philo[i]) != 0)
			return (NULL);
		i++;
	}
	return (philo);
}

t_info	*init_struct_info(int ac, char **av)
{
	t_info	*info;

	(void)ac;
	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->start_t = actual_time();
	info->number_of_philosophers = ft_atoi(av[1]);
	info->number_of_fork = info->number_of_philosophers;
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->must_eat = -1;
	info->stop = 1;
	if (av[5])
		info->must_eat = ft_atoi(av[5]);
	if (pthread_mutex_init(&info->write_mut, NULL) != 0)
		return (NULL);
	if (pthread_mutex_init(&info->dead, NULL) != 0)
		return (NULL);
	if (pthread_mutex_init(&info->time, NULL) != 0)
		return (NULL);
	return (info);
}

t_fork	*init_struct_fork(t_info *info)
{
	t_fork	*fork;
	int		i;

	i = 0;
	fork = malloc(sizeof(t_fork) * info->number_of_fork);
	if (!fork)
		return (NULL);
	while (i < info->number_of_fork)
	{
		fork[i].taken = 1;
		if (pthread_mutex_init(&fork[i].mutex, NULL) != 0)
			return (NULL);
		i++;
	}
	return (fork);
}

void	init_philo(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->number_of_philosophers)
	{
		philo[i].id = i + 1;
		philo[i].info = info;
		philo[i].left_fork = &info->forks[i];
		philo[i].right_fork = &info->forks[(i + 1) % \
			info->number_of_philosophers];
		philo[i].eat_count = 0;
		philo[i].last_meal = actual_time();
		i++;
	}
}
