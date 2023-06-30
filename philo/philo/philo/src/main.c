/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomat <ktomat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:08:22 by ktomat            #+#    #+#             */
/*   Updated: 2023/06/14 13:40:41 by ktomat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	args_error(int ac, char **av)
{
	(void)av;
	if (ac == 1)
	{
		printf("Philo work like this : ");
		printf("./philo nbr_philo die_time eat_time ");
		return (msg_error("sleep_time <nbr_of_meal_needed>"));
	}
	return (0);
}

int	parsing_args(int ac, char **av)
{
	if (!(ac == 5 || ac == 6))
		return (msg_error("Invalid Arguments : try with 5 or 6 Arguments"));
	if (check_args(ac, av) == 0)
		return (msg_error("Arguments take only positive numbers"));
	if (ft_atoi(av[1]) == 0)
		return (msg_error("Cannot have less than 1 Philo"));
	if (check_int(ac, av) == 0)
		return (msg_error("A value is bigger than the max int"));
	return (0);
}

void	init_data(int ac, char **av, t_table *table)
{
	table->times->die_time = ft_atoi(av[2]);
	table->times->eat_time = ft_atoi(av[3]);
	table->times->sleep_time = ft_atoi(av[4]);
	table->nbr_philo = ft_atoi(av[1]);
	table->status = 1;
	table->times->nbr_of_meal_needed = -1;
	if (ac == 6)
		table->times->nbr_of_meal_needed = ft_atoi(av[5]);
}

int	init(int ac, char **av, t_table *table, t_times *times)
{
	int		i;

	i = 0;
	if (pthread_mutex_init(&table->status1, NULL) != 0
		|| pthread_mutex_init(&table->print, NULL) != 0)
		return (msg_error("Mutex init fail"));
	table->times = times;
	table->nbr_philo = ft_atoi(av[1]);
	table->philo = malloc(sizeof(t_philo *) * table->nbr_philo);
	if (!table->philo)
		return (msg_error("Malloc error"));
	init_data(ac, av, table);
	while (i < table->nbr_philo)
	{
		table->philo[i].id = i + 1;
		table->philo[i].nbr_of_meal = 0;
		table->philo[i].times = times;
		table->philo[i].time_last_meal = get_actual_time();
		table->philo[i].table = table;
		if (pthread_mutex_init(&table->philo[i].fork, NULL) != 0
			|| pthread_mutex_init(&table->philo[i].lst_meal, NULL) != 0
			|| pthread_mutex_init(&table->philo[i++].meal, NULL) != 0)
			return (msg_error("Mutex init fail"));
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_table	table;
	t_times	times;

	if (args_error(ac, av) == -1 || parsing_args(ac, av) == -1)
		return (-1);
	if (init(ac, av, &table, &times) < 0)
	{
		destroy_mutex(&table);
		free_philo(&table);
		return (-1);
	}
	if (thread_start(&table) < 0)
	{
		destroy_thread(&table);
		destroy_mutex(&table);
		free_philo(&table);
		return (-1);
	}
	supervisor(&table);
	destroy_thread(&table);
	destroy_mutex(&table);
	free_philo(&table);
	return (0);
}
