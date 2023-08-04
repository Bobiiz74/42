/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_index_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:15:42 by robin             #+#    #+#             */
/*   Updated: 2023/07/31 15:59:58 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	g_env;

int	get_env_var_index(char *var)
{
	int	i;
	int	len;

	i = 0;
	len = strlen_until(var, "=");
	while (g_env.env[i] != NULL)
	{
		if (ft_strncmp(g_env.env[i], var, len) == 0 && g_env.env[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

int	get_env_var_index_nonequal(char *var)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(var);
	while (g_env.env[i] != NULL)
	{
		if (ft_strncmp(g_env.env[i], var, len) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_env_var_value(char *var_name)
{
	int		env_index;
	char	*value_start;

	env_index = get_env_var_index(var_name);
	if (env_index == -1)
		return (NULL);
	value_start = ft_strchr((char *)g_env.env[env_index], '=') + 1;
	if (value_start == NULL)
		return (NULL);
	return (ft_strdup(value_start));
}
