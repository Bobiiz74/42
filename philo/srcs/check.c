/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:31:16 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/06/30 15:54:44 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_info *info, t_philo *philo)
{	
	//pthread_mutex_lock(&info->time);
	if (actual_time() - philo->last_meal > (long)info->time_to_die)
	{
		//pthread_mutex_lock(&info->dead);
		//info->stop = 0;
		//pthread_mutex_unlock(&info->dead);
		pthread_mutex_lock(&info->write_mut);
		printf("%ld ", (long)info->time_to_die);
		printf("Philo %d died\n", philo->id);
		printf("yo");
		pthread_mutex_unlock(&info->write_mut);
		ft_exit(info);
		return (-1);
	}
	//pthread_mutex_unlock(&info->time);
	return (1);
}
