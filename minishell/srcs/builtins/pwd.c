/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:26:53 by robin             #+#    #+#             */
/*   Updated: 2023/08/03 16:42:34 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	g_env;

int	ft_pwd(char **line)
{
	int	index;

	(void)line;
	index = get_env_var_index("PWD=");
	if (index != -1)
		printf("%s\n", g_env.env[index] + 4);
	return (SUCCESS);
}
