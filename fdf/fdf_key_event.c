/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:15:41 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/01/20 18:27:17 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(int keycode, t_vars *vars)
{
	if (keycode != 53)
	{	
		printf("%s\n", "coucou1");
		mlx_destroy_window(vars->mlx, vars->win);
	}
	exit (0);
	return (0);
}

static int	print_key(int keycode, t_vars *vars)
{
	(void) vars;
	if (keycode == 53)
	{
		printf("%s\n", "coucou2");
		close_win(keycode, vars);
	}
	return (0);
}

static int	zoom_hook(int keycode, t_map *map)
{
	if (keycode == 126)
	{
		printf("%s\n", "zoom avant");
		map->zoom += 1.0;
	}
	else if (keycode == 125)
	{
		printf("%s\n", "zoom arriere");
		map->zoom -= 1.0;
	}
	return (0);
}

int	key_hook(int keycode, t_map *map, t_vars *vars)
{
	if (keycode == 53)
	{
		print_key(keycode, vars);
		close_win(keycode, vars);
	}
	if (keycode == 125 || keycode == 126)
		zoom_hook(keycode, map);
	return (0);
} 
