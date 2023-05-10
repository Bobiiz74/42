/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:23:24 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/05/10 17:37:35 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//dessine ligne par ligne puis column par column

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

//dessine la line x en transformant les coordonées des pts 
//dela ligne en points à l'ecran et dessine avec draw line

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

//calcul une translation de l'origine du repere pour centrer l'img
//projete le point 3D sur un plan 2D(translation)
//trasnf iso : cos et sin = angle de 30°
//screen->x et y: calcule la position sur l'écran
//(centre de la fenetre, position et zoom)

void	iso_transf(t_vec3 point, t_vec3 *screen, t_map *map)
{
	float	y_transf_iso;
	float	x_transf_iso;
	float	trsx;
	float	trsy;

	trsx = (float)(map->column / 2) * (-1);
	trsy = (float)(map->line / 2) * (-1);
	x_transf_iso = (point.x - point.y) * cos(0.523599);
	y_transf_iso = ((-1) * point.z + (point.x + point.y)) * sin(0.523599);
	screen->x = map->win_w / 2 + (x_transf_iso + trsx) * map->zoom;
	screen->y = map->win_h / 2 + (y_transf_iso + trsy) * map->zoom;
	screen->z = point.z;
}

//vérifie si le pixel (x/y) est bien a l'interieur des dimensions de l'img
//calcul l'addrs mémoire du pixel pour savoir ou il se situe sur l'img

void	pixel_2img(t_img *data, int x, int y, int color)
{
	char	*dst;

	data->color = color;
	if ((x > 0 && x <= data->win_w) && (y > 0 && y < data->win_h))
	{
		dst = data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
