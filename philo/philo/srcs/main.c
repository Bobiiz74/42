/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:08:22 by robin             #+#    #+#             */
/*   Updated: 2023/07/05 14:54:09 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_error(int ac, char **av)
{
	(void)av;
	if (ac == 1)
	{
		printf("Philo usage : ");
		printf("./philo nbr_philo time_to_die time_to_eat \
			time_to_sleep [nbr_of_meal] ");
		return (print_error("sleep_time <nbr_of_meal_needed>"));
	}
	return (0);
}

int	parsing_args(int ac, char **av)
{
	if (!(ac == 5 || ac == 6))
		return (print_error("Invalid Arguments : try with 5 or 6 Arguments"));
	if (check_args(ac, av) == 0)
		return (print_error("Arguments take only positive numbers"));
	if (ft_atoi(av[1]) == 0)
		return (print_error("Cannot have less than 1 Philo"));
	if (check_int(ac, av) == 0)
		return (print_error("A value is bigger than the max int"));
	return (0);
}

void	init_data(int ac, char **av, t_info *info)
{
	info->times->die_time = ft_atoi(av[2]);
	info->times->eat_time = ft_atoi(av[3]);
	info->times->sleep_time = ft_atoi(av[4]);
	info->nbr_philo = ft_atoi(av[1]);
	info->status = 1;
	info->times->nbr_of_meal_needed = -1;
	if (ac == 6)
		info->times->nbr_of_meal_needed = ft_atoi(av[5]);
}

int	init(int ac, char **av, t_info *info, t_times *times)
{
	int		i;

	i = 0;
	if (pthread_mutex_init(&info->status1, NULL) != 0
		|| pthread_mutex_init(&info->write, NULL) != 0)
		return (print_error("Mutex init fail"));
	info->times = times;
	info->nbr_philo = ft_atoi(av[1]);
	info->philo = malloc(sizeof(t_philo *) * info->nbr_philo);
	if (!info->philo)
		return (print_error("Malloc error"));
	init_data(ac, av, info);
	while (i < info->nbr_philo)
	{
		info->philo[i].id = i + 1;
		info->philo[i].nbr_of_meal = 0;
		info->philo[i].times = times;
		info->philo[i].time_last_meal = get_actual_time();
		info->philo[i].info = info;
		if (pthread_mutex_init(&info->philo[i].fork, NULL) != 0
			|| pthread_mutex_init(&info->philo[i].last_meal, NULL) != 0
			|| pthread_mutex_init(&info->philo[i++].meal, NULL) != 0)
			return (print_error("Mutex init fail"));
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_info	info;
	t_times	times;

	if (args_error(ac, av) == -1 || parsing_args(ac, av) == -1)
		return (-1);
	if (init(ac, av, &info, &times) < 0)
	{
		destroy_mutex(&info);
		free_philo(&info);
		return (-1);
	}
	if (thread_start(&info) < 0)
	{
		destroy_thread(&info);
		destroy_mutex(&info);
		free_philo(&info);
		return (-1);
	}
	supervisor(&info);
	destroy_thread(&info);
	destroy_mutex(&info);
	free_philo(&info);
	return (0);
}
