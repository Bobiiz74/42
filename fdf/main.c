/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:18:48 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/01/26 17:24:38 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int	err;

	err = 0;
	if (argc == 1)
	{
		errno = EINVAL;
		perror("Rentrez le nom de la map apres ./fdf !");
	}
	else if (argc == 2)
		err = fdf_core(argv[1]);
	else
	{
		errno = E2BIG;
		perror("Trop d'arguments, choisissez une seule map !");
	}
	return (err);
}

int	fdf_core(char *path)
{
	t_map		map;
	t_vars		vars;
	t_img		img;

	if (!check_extension(path))
	{
		errno = EINVAL;
		perror("Wrong format !");
		exit(-1);
	}
	if (!main_parser(path, &map))
		exit(-1);
	map.zoom = set_zoom(&map);
	vars.mlx = mlx_init();
	img.win_h = map.win_h;
	img.win_w = map.win_w;
	vars.win = mlx_new_window(vars.mlx, img.win_w, img.win_h, "FdF");
	img.img = mlx_new_image(vars.mlx, img.win_w, img.win_h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);	
	map.img = &img;
	map.vars = &vars;
	transfer_2_screen(&map, &img);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	print_info(&vars);
	mlx_hook(vars.win, 2, 0, key_hook, &map);
	mlx_loop(vars.mlx);
	return (0);
}
