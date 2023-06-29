/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:27:05 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/06/28 17:09:32 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	*info;

	if ((argc == 5 || argc == 6) && numeric(argv, 0, 1))
	{
		info = init_struct_info(argc, argv);
		if(info->number_of_philosophers == 1)
		{
			one_philo(info->time_to_die);
			return (free(info), 0);
		}
		info->forks = init_struct_fork(info);
		info->philos = init_struct_philo(info);
		if (argc == 6)
			check_all_eat(info);
		if (!info->philos || !info || !info->forks)
		{
			ft_putstr_fd("Error: Memory allocation failed\n", 2);
			return (1);
		}
		ft_exit(info);
	}
	else
		ft_putstr_fd("Error: Invalid arguments\n", 2);
	return (0);
}

void	check_all_eat(t_info *info)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < info->number_of_philosophers)
	{
		if (info->philos[i].eat_count == info->must_eat)
			j += 1;
		if (j == info->number_of_philosophers)
			printf("Each philosopher ate %d time(s)\n", info->must_eat);
		i++;
	}
}

void	free_all(t_info *info)
{
	if (info->philos)
		free(info->philos);
	if (info->forks)
		free(info->forks);
	if (info)
		free(info);
}

void	ft_exit(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_fork)
	{
		pthread_mutex_destroy(&info->forks[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&info->write_mut);
	pthread_mutex_destroy(&info->dead);
	free_all(info);
}

int	numeric(char **argv, int i, int j)
{
	while (argv[j])
	{
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9' || ft_strlen(argv[j]) > 10)
				return (0);
			if (ft_atoi(argv[j]) <= 0)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}
