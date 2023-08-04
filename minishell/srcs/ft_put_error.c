/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:30:16 by ppotier           #+#    #+#             */
/*   Updated: 2023/07/13 13:30:17 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_put_error(char *cause, const char *err_msg)
{
	char	*err;

	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(cause, 2);
	ft_putstr_fd(": ", 2);
	err = ft_strdup(err_msg);
	if (!err)
		ft_putstr_fd("could not allocate err msg", 2);
	else
	{
		ft_putstr_fd(err, 2);
		free(err);
	}
	ft_putstr_fd("\n", 2);
}
