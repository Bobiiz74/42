/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:56:24 by robin             #+#    #+#             */
/*   Updated: 2023/08/03 18:00:17 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	list_len(char **list)
{
	int		i;

	i = 0;
	while (list[i] != NULL)
		i++;
	return (i);
}

int	add_env_var(char *var)
{
	char	**new_env_copy;
	int		i;

	new_env_copy
		= (char **)malloc(sizeof(char *) * (list_len(g_env.env) + 2));
	if (new_env_copy == NULL)
		return (ERROR);
	i = 0;
	while (g_env.env[i])
	{
		new_env_copy[i] = g_env.env[i];
		i++;
	}
	new_env_copy[i] = var;
	new_env_copy[i + 1] = NULL;
	free(g_env.env);
	g_env.env = new_env_copy;
	return (SUCCESS);
}
