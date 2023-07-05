/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:18:49 by robin             #+#    #+#             */
/*   Updated: 2023/07/05 14:12:03 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	get_actual_time(void)
{
	unsigned long long		time;
	struct timeval			current_time;

	gettimeofday(&current_time, NULL);
	time = current_time.tv_sec * 1000;
	time += current_time.tv_usec / 1000;
	return (time);
}

void	ft_usleep(unsigned long long milliseconde)
{
	unsigned long long	start_time;
	unsigned long long	timer_ms;

	start_time = get_actual_time();
	timer_ms = get_time_pass(start_time, get_actual_time());
	while (timer_ms < milliseconde)
	{
		timer_ms = get_time_pass(start_time, get_actual_time());
		usleep(milliseconde / 10);
	}
}

long long int	get_time_pass(unsigned long long start,
	unsigned long long end)
{
	return (end - start);
}
