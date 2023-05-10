/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:52:51 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/05/10 18:36:48 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	print_info(t_vars *vars)
{	
	mlx_string_put(vars->mlx, vars->win, 10, 5, \
				0xffffff, "Deplacements : W / A / S / D");
	mlx_string_put(vars->mlx, vars->win, 10, 30, \
				0xffffff, "Zoom : Fleche en Haut / Fleche en Bas ");
	mlx_string_put(vars->mlx, vars->win, 10, 55, \
				0xffffff, "Couleur : R / G / B");
}

int	color_hook(int keycode)
{	
	int	color;

	color = 0;
	if (keycode == 15)
		color = 0x00FF0000;
	if (keycode == 5)
		color = 0x0000FF00;
	if (keycode == 11)
		color = 0x000000FF;
	return (color);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
