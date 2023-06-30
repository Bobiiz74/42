/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomat <ktomat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:11:31 by ktomat            #+#    #+#             */
/*   Updated: 2023/06/13 13:11:08 by ktomat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	msg_error(char *str)
{
	printf("%s\n", str);
	return (-1);
}

void	free_philo(t_table *table)
{
	free(table->philo);
}

void	destroy_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i != table->nbr_philo)
	{
		pthread_mutex_destroy(&table->philo[i].fork);
		pthread_mutex_destroy(&table->philo[i].lst_meal);
		pthread_mutex_destroy(&table->philo[i].meal);
		i++;
	}
	pthread_mutex_destroy(&table->status1);
	pthread_mutex_destroy(&table->print);
}

void	destroy_thread(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nbr_philo)
	{
		pthread_join(table->philo[i].thread, NULL);
		i++;
	}
}
