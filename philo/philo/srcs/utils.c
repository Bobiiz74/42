/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:09:19 by robin             #+#    #+#             */
/*   Updated: 2023/07/05 14:53:09 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_atoi(const char *str)
{
	int			i;
	long int	result;
	int			u;

	i = 0;
	result = 0;
	u = 1;
	if (str[0] == '-')
		return (0);
	if (str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * u);
}

int	check_int(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) < MIN_INT || ft_atoi(av[i]) > MAX_INT)
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	supervisor(t_info *info)
{
	while (1)
	{
		if (check_death(info) == -1)
		{
			return ;
		}
		else if (check_meal(info) == -1)
		{
			return ;
		}
	}
	return ;
}
