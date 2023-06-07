/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:27:05 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/06/07 16:44:25 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	*info;	

	if (argc == 5 || argc == 6)
	{
		info = init_struct_info(argc, argv);
		info->forks = init_struct_fork(info);
		info->philos = init_struct_philo(info);
		if (!info->philos || !info || !info->forks)
		{
			ft_putstr_fd("Error: Memory allocation failed\n", 2);
			return (1);
		}
		free(info->philos);
		free(info);
		free(info->forks);
	}
	else
		ft_putstr_fd("Error: Invalid arguments\n", 2);
	return (0);
}
