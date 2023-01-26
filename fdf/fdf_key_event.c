/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:15:41 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/01/24 17:03:57 by rgodtsch         ###   ########.fr       */
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
		printf("%f\n", map->zoom);
	if (keycode == 126)
	{
		printf("%f\n", map->zoom);
		printf("%s\n", "zoom avant");
		map->zoom += 1.0;
		printf("%f\n", map->zoom);
	}
	else if (keycode == 125)
	{
		printf("%s\n", "zoom arriere");
		if (map->zoom > 0)
			map->zoom -= 1.0;
		printf("%f\n", map->zoom);

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
	{
		printf("key hook%f\n", map->zoom);		
		mlx_clear_window(map->vars->mlx,  map->vars->win);
		zoom_hook(keycode, map, vars);
		transfer_2_screen(map, map->img);
		mlx_put_image_to_window(map->vars->mlx, map->vars->win, map->img->img, 0 , 0);
	}
	return (0);
} 

/*int	render_next_frame(t_map *map)
{
	//mlx_new_image(map->vars->mlx, map->img->win_w, map->img->win_h);
	transfer_2_screen(map, map->img);
	mlx_put_image_to_window(map->vars->mlx, map->vars->win, map->img->img, 0 , 0);
	return (0);
}*/

