/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:29:11 by ppotier           #+#    #+#             */
/*   Updated: 2023/07/28 15:44:33 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ms_getenv_cont(char *name)
{
	int		i;
	char	*match;

	i = 0;
	while (g_env.env[i] != 0)
	{
		match = ft_strnstr(g_env.env[i], name, ft_strlen(g_env.env[i]));
		if (match)
		{
			if (match == g_env.env[i] && match[ft_strlen(name)] == '=')
				return (ft_strdup(g_env.env[i] + (ft_strlen(name)) + 1));
		}
		i++;
	}
	return (NULL);
}

char	*ms_getenv(char	*name)
{
	int		i;
	char	*match;

	i = 0;
	while (g_env.env[i] != 0)
	{
		match = ft_strnstr(g_env.env[i], name, ft_strlen(g_env.env[i]));
		if (match)
		{
			if (match == g_env.env[i] && match[ft_strlen(name)] == '=')
				return (ft_strdup(g_env.env[i]));
		}
		i++;
	}
	return (NULL);
}
