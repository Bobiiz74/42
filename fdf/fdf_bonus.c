/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:52:51 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/01/28 14:05:34 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	print_info(t_vars *vars)
{	
	mlx_string_put(vars->mlx, vars->win, 10, 5, \
				0xffffff, "Deplacements : W / A / S / D");
	mlx_string_put(vars->mlx, vars->win, 10, 30, \
				0xffffff, "Zoom : Fleche en Haut / Fleche en Bas ");
}

int	color_hook(int keycode, t_vars *vars)
{
	if (keycode == 15)
		vars->img->color = 0x00FF0000;
	if (keycode == 5)
		vars->img->color = 0x0000FF00;
	if (keycode == 11)
		vars->img->color = 0x000000FF;
	return (0);
}
