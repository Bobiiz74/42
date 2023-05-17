/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:24:25 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/05/15 17:42:17 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*int *init_struct(int ac, char **av)
{
	
}*/

t_philo	*init_struct_philo(t_info *info)
{
	t_philo	*philo;
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
		philo[i].info = info;
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
		if (pthread_mutex_init(&fork[i].mutex, NULL) != 0)
			return (NULL);
		fork[i].taken = 0;
		i++;
	}
	return (fork);
}
