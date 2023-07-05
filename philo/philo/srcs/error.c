/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:11:31 by robin             #+#    #+#             */
/*   Updated: 2023/07/05 14:20:50 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *str)
{
	printf("%s\n", str);
	return (-1);
}

void	free_philo(t_info *info)
{
	free(info->philo);
}

void	destroy_mutex(t_info *info)
{
	int	i;

	i = 0;
	while (i != info->nbr_philo)
	{
		pthread_mutex_destroy(&info->philo[i].fork);
		pthread_mutex_destroy(&info->philo[i].last_meal);
		pthread_mutex_destroy(&info->philo[i].meal);
		i++;
	}
	pthread_mutex_destroy(&info->status1);
	pthread_mutex_destroy(&info->write);
}

void	destroy_thread(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nbr_philo)
	{
		pthread_join(info->philo[i].thread, NULL);
		i++;
	}
}
