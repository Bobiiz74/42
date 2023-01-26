/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:52:51 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/01/26 17:38:53 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	print_info(t_vars *vars)
{	
	mlx_string_put(vars->mlx, vars->win, 10, 5, \
				0xffffff, "Deplacements : W / A / S / D");
	mlx_string_put(vars->mlx, vars->win, 10, 30, \
				0xffffff, "Zoom Avant / Arriere : Fleche du Haut / Fleche du Bas");
}
