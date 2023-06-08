/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:31:16 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/06/08 15:03:58 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_info *info, t_philo *philo)
{
	(void)info;
	(void) philo;
	return (1);
}

void is_dead(t_info *info, t_philo *philo)
{
	if(info->start_t - philo->last_meal >= info->time_to_die)
	{
		write_status("died\n", philo, info);
	}
}
