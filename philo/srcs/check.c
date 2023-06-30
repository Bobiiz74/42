/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:31:16 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/06/30 16:52:01 by ppotier          ###   ########.fr       */
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
		// pthread_mutex_unlock(&info->dead);
		pthread_mutex_lock(&info->write_mut);
		printf("%ld ", actual_time() - philo->last_meal);
		printf("Philo %d died\n", philo->id);
		// ft_join(info);
		ft_exit(info);
		// pthread_mutex_unlock(&info->write_mut);
		return (-1);
	}
	else
		return (1);
	//pthread_mutex_unlock(&info->time);
}
