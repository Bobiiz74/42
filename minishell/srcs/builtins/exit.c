/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 12:23:02 by robin             #+#    #+#             */
/*   Updated: 2023/08/04 15:00:29 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_minishell(void)
{
	split_free(g_env.env);
	rl_clear_history();
}

static int	ft_ascii_is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (ERROR);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	ft_exit(char **argv)
{
	int	len;
	int	exit_status;

	len = 0;
	exit_status = 0;
	while (argv != NULL && argv[len] != NULL)
		len++;
	if (len >= 2)
	{
		exit_status = ft_atoi(argv[1]);
		if (ft_ascii_is_valid_number(argv[1]))
		{
			ft_putendl_fd("minishell: exit: numeric argument required", 2);
			exit_status = 255;
		}
		if (len > 2)
		{
			ft_putendl_fd("minishell: exit: too many arguments", 2);
			return (ERROR);
		}
	}
	free_minishell();
	printf("exit\n");
	exit(exit_status);
	return (SUCCESS);
}
