/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:23:24 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/01/19 15:42:27 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	transfer_2_screen(t_map *map, t_img *data)
{
	int		x;

	x = 0;
	while (x < map->line)
	{
		line_2_img(map, data, x);
		x++;
	}
	x = 0;
	while (x < map->column)
	{
		column_2_img(map, data, x);
		x++;
	}
}

void	line_2_img(t_map *map, t_img *data, int x)
{
	int		i;
	t_vec3	pt1_sc;
	t_vec3	pt2_sc;

	i = 1;
	while (i < map->column)
	{
		iso_transf(map->tab_line[x].tab_pts[i - 1], &pt1_sc, map);
		iso_transf(map->tab_line[x].tab_pts[i], &pt2_sc, map);
		draw_line(pt1_sc, pt2_sc, data);
		i++;
	}
}

void	column_2_img(t_map *map, t_img *data, int x)
{
	int		i;
	t_vec3	pt1_sc;
	t_vec3	pt2_sc;

	i = 1;
	while (i < map->line)
	{
		iso_transf(map->tab_line[i - 1].tab_pts[x], &pt1_sc, map);
		iso_transf(map->tab_line[i].tab_pts[x], &pt2_sc, map);
		draw_line(pt1_sc, pt2_sc, data);
		i++;
	}
}

void	iso_transf(t_vec3 point, t_vec3 *screen, t_map *map)
{
	//float	zoom;
	float	y_transf_iso;
	float	x_transf_iso;
	float	trsx;
	float	trsy;
	
	map->zoom = 1.0 * set_zoom(map);
	trsx = (float)(map->column / 2) * (-1);
	trsy = (float)(map->line / 2) * (-1);
	x_transf_iso = (point.x - point.y) * cos(0.523599);
	y_transf_iso = ((-1) * point.z + (point.x + point.y)) * sin(0.523599);
	screen->x = map->win_w / 2 + (x_transf_iso + trsx) * map->zoom;
	screen->y = map->win_h / 2 + (y_transf_iso + trsy) * map->zoom;
	screen->z = point.z;
}

void	pixel_2img(t_img *data, int x, int y, int color)
{
	char	*dst;

	if ((x > 0 && x <= data->win_w) && (y > 0 && y < data->win_h))
	{
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	}
}
