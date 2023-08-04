/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:45:54 by robin             #+#    #+#             */
/*   Updated: 2023/08/03 16:17:26 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	g_env;

static int	check_args(char **split_line)
{
	if (split_line[1] != NULL)
	{
		write(2, "minishell: env: too many arguments\n", 34);
		return (ERROR);
	}
	return (SUCCESS);
}

int	ft_env(char **split_line)
{
	int		i;

	if (check_args(split_line) == ERROR)
		return (ERROR);
	i = 0;
	while (g_env.env[i] != NULL)
	{
		printf("%s\n", g_env.env[i]);
		i++;
	}
	return (SUCCESS);
}
