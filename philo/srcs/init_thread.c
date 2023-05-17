/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:45:41 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/05/15 17:48:01 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_philo(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	int id;
//	int	time_to_die;

	philo = (t_philo *) arg;
	info = philo->info;
	id = philo->id;
	(void) info;
	//time_to_die = *((int *)arg + 1);
	printf("Philosophe %d : Début du thread\n", id);
	sleep(2);
	printf("Philosophe %d : Fin du thread\n", id);
	return (NULL);
}




int	init_philo(t_info *info, t_philo *philo)
{
	pthread_t	thread_id[info->number_of_philosophers];
	int			i;

	i = 0;
	while (i < info->number_of_philosophers)
	{
		philo[i].id = i + 1;
		philo[i].info = info;
		if (pthread_create(&thread_id[i], NULL, &routine_philo, &philo[i]) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < info->number_of_philosophers)
	{
		if (pthread_join(thread_id[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
	}


