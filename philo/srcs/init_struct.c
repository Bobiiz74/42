/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:24:25 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/06/03 14:40:37 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*int *init_struct(int ac, char **av)
{
	
}*/

t_philo	*init_struct_philo(t_info *info)
{
	t_philo	*philo;
	pthread_t	thread_id[info->number_of_philosophers];
	int		nb_philo;
	int		i;

	nb_philo = info->number_of_philosophers;
	philo = malloc(sizeof(t_philo) * nb_philo);
	if (!philo)
		return (NULL);
	i = 0;
	while (i < nb_philo)
	{
		philo[i].id = i + 1;
		//printf("id%d\n", philo[i].id);
		philo[i].info = info;
		if (pthread_create(&thread_id[i], NULL, &routine_philo, &philo[i]) != 0)
			return (NULL);
		philo[i].left_fork = &info->forks[i];
		philo[i].right_fork = &info->forks[(i + 1) % info->number_of_philosophers];
		//printf("left%p\n", philo[i].left_fork);
		//printf("right%p\n", philo[i].right_fork);
		i++;
	}
	i = 0;
	while (i < info->number_of_philosophers)
	{
		if (pthread_join(thread_id[i], NULL) != 0)
			return (NULL);
		i++;
	}
	return (philo);
}

t_info  *init_struct_info(int ac, char **av)
{
    t_info  *info;

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
    if (av[5])
        info->must_eat = ft_atoi(av[5]);
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
