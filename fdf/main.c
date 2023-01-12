/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:18:48 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/01/10 18:13:42 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "./mlx_macos/mlx.h"

typedef struct	s_vars {
	void 	*mlx;
	void 	*win;
	
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_vars;

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	double pixelX = beginX;
	double pixelY = beginY;
	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0

	while (pixels)
	{
  	  mlx_pixel_put(mlx, win, pixelX, pixelY, color);
  	  pixelX += deltaX;
  	  pixelY += deltaY;
  	  --pixels;
	}
	return (0);

}



int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 666, 666, "Fil de Fer");
	vars.img = mlx_new_image(vars.mlx, 666, 666);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length,
								&vars.endian);
	my_mlx_pixel_put(&vars, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 200, 300);
	draw_line(vars.mlx, vars.win, 666, 666, 0, 0, 0x00FF0000);	
	mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);
	mlx_loop(vars.mlx);
	return (0);
}


