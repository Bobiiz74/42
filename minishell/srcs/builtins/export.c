/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:04:04 by robin             #+#    #+#             */
/*   Updated: 2023/08/03 18:06:00 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_var_name(char *var)
{
	int	len;

	len = ft_strlen(var);
	if (len == 1)
	{
		if (ft_isalpha(var[0]))
			return (3);
		ft_putendl_fd("minishell: export: not a valid identifier3", 2);
		return (ERROR);
	}
	else
	{
		if (var[0] == '_' && var[1] == '=')
			return (3);
	}
	return (SUCCESS);
}

int	export_one_arg(char *var)
{
	char	*new_var;
	int		var_index;
	int		status;

	status = check_var_name(var);
	if (status == ERROR)
		return (ERROR);
	if (status == 3)
		return (SUCCESS);
	new_var = ft_strdup(var);
	if (new_var == NULL)
		return (ERROR);
	var_index = get_env_var_index(new_var);
	if (var_index == -1 && add_env_var(new_var) == ERROR)
	{
		free(new_var);
		return (ERROR);
	}
	else if (var_index != -1)
	{
		free(g_env.env[var_index]);
		g_env.env[var_index] = new_var;
	}
	return (SUCCESS);
}

void	sort_env(void)
{
	char	**dup;
	char	*tmp;
	size_t	i;
	size_t	j;

	dup = g_env.env;
	i = 0;
	while (dup[i])
	{
		j = i + 1;
		while (dup[j])
		{
			if (ft_strcmp(dup[i], dup[j]) > 0)
			{
				tmp = dup[i];
				dup[i] = dup[j];
				dup[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	print_all_env(void)
{
	int		i;

	i = 0;
	while (g_env.env[i] != NULL)
	{
		printf("declare -x %s\n", g_env.env[i]);
		i++;
	}
	return (SUCCESS);
}

int	ft_export(char **split_line)
{
	int	last_status;
	int	i;

	i = 1;
	if (split_line[1] == NULL)
	{
		sort_env();
		return (print_all_env());
	}
	else
	{
		while (split_line[i] != NULL)
		{
			last_status = export_one_arg(split_line[i]);
			i++;
		}
	}
	return (last_status);
}
