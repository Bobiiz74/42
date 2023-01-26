/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:15:41 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/01/26 17:43:57 by rgodtsch         ###   ########.fr       */
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

int	zoom_hook(int keycode, t_map *map, t_vars *vars)
{
	(void) vars;
	if (keycode == 126)
		map->zoom += 1.0;
	else if (keycode == 125)
		if (map->zoom > 0)
			map->zoom -= 1.0;
	return (0);
}

int	moove_hook(int keycode, t_map *map, t_vars *vars)
{
	(void) vars;
	if (keycode == 13)
		map->win_h -= 10;
	if (keycode == 1)
		map->win_h += 10;
	if (keycode == 0)
		map->win_w -= 10;
	if (keycode == 2)
		map->win_w += 10;
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
	{
		zoom_hook(keycode, map, vars);
		mlx_destroy_image(map->vars->mlx, map->img->img);
		map->img->img = mlx_new_image(map->vars->mlx,
				map->img->win_w, map->img->win_h);
		transfer_2_screen(map, map->img);
		mlx_put_image_to_window(map->vars->mlx,
			map->vars->win, map->img->img, 0, 0);
	}
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		moove_hook(keycode, map, vars);
		mlx_destroy_image(map->vars->mlx, map->img->img);
		map->img->img = mlx_new_image(map->vars->mlx,
				map->img->win_w, map->img->win_h);
		transfer_2_screen(map, map->img);
		mlx_put_image_to_window(map->vars->mlx,
			map->vars->win, map->img->img, 0, 0);
	}
	return (0);
}
