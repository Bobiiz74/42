/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:15:41 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/01/14 17:57:04 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}

int	print_key(int keycode, t_vars *vars)
{
	(void) vars;
	if (keycode == 53)
		close_win(keycode, vars);
	return (0);
}

int	mouse_hook(int keycode, t_vec3 *screen)
{
	if (keycode == 4)
	{
		screen->x *= 2;
		screen->y *= 2;
	}
	else if (keycode == 5)
	{
		screen->x /= 2;
		screen->y /= 2;
	}
	return (0);
}
