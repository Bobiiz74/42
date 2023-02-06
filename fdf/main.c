/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:18:48 by rgodtsch          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/02/06 17:06:12 by rgodtsch         ###   ########.fr       */
=======
/*   Updated: 2023/02/04 15:14:53 by rgodtsch         ###   ########.fr       */
>>>>>>> 7dbaf72d18d961799bb466ee7e244ffa61e6f078
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
		perror("Trop d'arguments !");
	}
	if (!check_extension(argv[1]))
	{
		errno = EINVAL;
		perror("Wrong format !");
		exit(-1);
	}
	return (err);
}

int	fdf_core(char *path)
{
	t_map		map;
	t_vars		vars;
	t_img		img;

	if (!main_parser(path, &map))
		exit(-1);
	map.zoom = set_zoom(&map);
	vars.mlx = mlx_init();
	img.color = 0x696969;
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
	mlx_hook(vars.win, 17, 0, close_win, &map);
	mlx_loop(vars.mlx);
	return (0);
}
