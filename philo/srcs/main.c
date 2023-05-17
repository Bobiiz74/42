/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:27:05 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/05/15 17:47:27 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	t_philo	*philo;
	t_fork	*all_fork;

	if (argc == 5 || argc == 6)
	{
		info = init_struct_info(argc, argv);
		philo = init_struct_philo(info);

		init_philo(info, philo);
		all_fork = init_struct_fork(info);
		if (!philo || !info || !all_fork)
		{
			ft_putstr_fd("Error: Memory allocation failed\n", 2);
			return (1);
		}
		free(philo);
		free(info);
		free(all_fork);
	}
	else
		ft_putstr_fd("Error: Invalid arguments\n", 2);
	return (0);
}
