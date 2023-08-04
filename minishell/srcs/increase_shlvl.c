/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_shlvl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:03:26 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/03 14:17:21 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	increase_shlvl(void)
{
	char	*shlvl;
	char	*export_args[3];
	char	*tmp;
	int		nblvl;

	shlvl = ms_getenv_cont("SHLVL");
	export_args[0] = "export";
	export_args[2] = NULL;
	if (!shlvl)
		export_args[1] = ft_strjoin("SHLVL=", "1");
	else
	{
		nblvl = ft_atoi(shlvl) + 1;
		free(shlvl);
		tmp = ft_itoa(nblvl);
		export_args[1] = ft_strjoin("SHLVL=", tmp);
		free(tmp);
	}
	ft_export(export_args);
	free(export_args[1]);
}
