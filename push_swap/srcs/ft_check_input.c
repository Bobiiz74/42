/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:30:40 by ppotier           #+#    #+#             */
/*   Updated: 2023/05/17 18:00:08 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

int	check_doubles(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[j])
		{
			if (j != i && nb_cmp(av[i], av[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	args_is_digit(char *str)
{
	int	i;

	i = 0;
	if (ft_is_sign(str[i]) && str[i + 1] != '\0')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0' && !ft_isdigit(str[i]))
		return (0);
	return (1);
}

int	args_is_zero(char *str)
{
	int	i;

	i = 0;
	if (ft_is_sign(str[i]))
		i++;
	while (str[i] && str[i] == '0')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	ft_check_input(int ac, char **av)
{
	char	**args;
	char	**tmp;
	int		nb_zeros;

	nb_zeros = 0;
	args = NULL;
	if (ac == 2)
		args = ft_split_args(av[1]);
	else
		args = ++av;
	tmp = args;
	if (!is_valid_args(args, ac))
		return (0);
	while (*args)
	{
		nb_zeros += args_is_zero(*args);
		args++;
	}
	args = tmp;
	if (nb_zeros > 1)
		return (ft_putendl_fd("Error", 2), 0);
	if (ac == 2)
		ft_free(args);
	return (1);
}
