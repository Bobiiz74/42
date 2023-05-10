/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:54:22 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/05/10 18:31:37 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include "./mlx_macos/mlx.h"
# include "./libft/libft.h"

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		win_w;
	int		win_h;
	int		color;
}	t_img;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_img		*pic;
	t_img		*img;

}	t_vars;

typedef struct s_vec3 {
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_vec2 {
	int	x;
	int	y;
}	t_vec2;

typedef struct s_line {
	t_vec3	*tab_pts;
}	t_line;

typedef struct s_map {
	char	*path;
	int		line;
	int		column;
	int		max_h;
	int		win_w;
	int		win_h;
	float	zoom;
	t_line	*tab_line;
	t_img	*img;
	t_vars	*vars;
}	t_map;

//main.c
int		main(int argc, char **argv);
int		fdf_core(char *path);

//file_2_data.c
int		main_parser(char *path, t_map *map);
int		map_parser(int fd, t_map *map);
void	get_first_info_parser(char *line, t_map *map);
t_line	*get_next_pts_line(t_map *map, char **tab);
int		new_line_2_tab(char *line, t_map *map);

//utils
int		check_extension(char *path);
int		check_line(char *str);
void	free_t_line(t_line *line, int len);
void	set_window_size(t_map *map);
float	set_zoom(t_map *map);

//vec
void	ft_cp_vec3(t_vec3 point, t_vec3 *new_vec);
void	print_vec3(t_vec3 vec);
int		ft_val_in_r(int v, int min, int max);
char	*ft_free_tab(void **tab, int len);
int		vec3_in_screen(t_vec3 vec, int max_L, int max_H);
//Keyevent  
int		close_win(int keycode, t_vars *vars);
int		key_hook(int keycode, t_map *map, t_vars *vars);
int		render_next_frame(t_map *map);

//fdf_mlx.c
void	transfer_2_screen(t_map *map, t_img *data);
void	column_2_img(t_map *map, t_img *data, int x);
void	line_2_img(t_map *map, t_img *data, int x);
void	iso_transf(t_vec3 point, t_vec3 *screen, t_map *map);
void	pixel_2img(t_img *data, int x, int y, int color);

// fdf_bresenham.c
void	case_dx_dy(t_vec2 e, t_vec3 p1, t_vec3 p2, t_img *data);
void	case_dy_dx(t_vec2 e, t_vec3 p1, t_vec3 p2, t_img *data);
void	draw_line(t_vec3 p1, t_vec3 p2, t_img *data);

// fdf_bonus.c
void	print_info(t_vars *vars);
int		color_hook(int keycode);
int		create_trgb(int t, int r, int g, int b);
#endif
