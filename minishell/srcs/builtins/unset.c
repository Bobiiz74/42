/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:58:09 by robin             #+#    #+#             */
/*   Updated: 2023/08/04 16:10:32 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	remove_env_var(int index_var)
{
	int		last;

	last = 0;
	while (g_env.env[last] != NULL)
		last++;
	free(g_env.env[index_var]);
	g_env.env[index_var] = g_env.env[last - 1];
	g_env.env[last - 1] = NULL;
	return (SUCCESS);
}

static int	unset_one_variable(char *line)
{
	int		var_index;
	int		i;
	int		flag;

	flag = 0;
	if (ft_isdigit(line[0]) != 0)
		return (SUCCESS);
	i = -1;
	while (line[++i] && (ft_isdigit(line[i]) 
			|| ft_isalpha(line[i]) || line[i] == '_'))
		if (line[i] == '=')
			flag = 1;
	if (line[i] != '\0')
		return (SUCCESS);
	line[i] = '\0';
	if (flag == 1)
		var_index = get_env_var_index(line);
	else
		var_index = get_env_var_index_nonequal(line);
	if (var_index == -1)
		return (SUCCESS);
	remove_env_var(var_index);
	return (SUCCESS);
}

int	ft_unset(char **split_line)
{
	int	last_status;
	int	i;

	if (split_line[1] == NULL)
		return (SUCCESS);
	i = 0;
	while (++i && split_line[i])
		last_status = unset_one_variable(split_line[i]);
	return (last_status);
}
