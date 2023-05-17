/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:52:56 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/05/17 18:01:06 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_split_args(char *str)
{
	char	**args;

	args = ft_split(str, ' ');
	if (!args)
		return (0);
	return (args);
}

int	is_valid_args(char **args, int ac)
{
	char	**tmp;

	tmp = args;
	if (!check_doubles(args))
	{
		if (ac == 2)
			ft_free(args);
		return (ft_putendl_fd("Error", 2), 0);
	}
	while (*args)
	{
		if (!ft_check_int(*args) || (!args_is_digit(*args)))
		{
			args = tmp;
			if (ac == 2)
				ft_free(args);
			return (ft_putendl_fd("Error", 2), 0);
		}
		args++;
	}
	return (1);
}
