/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:31:16 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/06/26 17:57:45 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_dead(t_info *info, t_philo *philo)
{		
	if (actual_time() - philo->last_meal > (long)info->time_to_die)
	{
		pthread_mutex_lock(&info->dead);
		info->stop = 0;
		pthread_mutex_unlock(&info->dead);
		pthread_mutex_lock(&info->write_mut);
		printf("%ld ", ((long)info->time_to_die + 1));
		printf("Philo %d died\n", philo->id);
		pthread_mutex_unlock(&info->write_mut);
	}
}
