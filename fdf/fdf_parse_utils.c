/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:31:55 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/01/15 14:42:19 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_extension(char *path)
{
	char	**tab;
	int		i;
	int		c;

	tab = ft_split(path, '.');
	if (!tab)
	{
		errno = ENOMEM;
		perror("Wrong format !");
		exit(-1);
	}
	i = 0;
	while (tab[i])
		i++;
	if (i != 2)
		c = 0;
	else if (ft_strncmp("fdf", tab[1], fmax(3, ft_strlen(tab[1]))))
		c = 0;
	else
		c = 1;
	ft_free_tab((void **)tab, i);
	return (c);
}

int	check_line(char *str)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	while (str[i] && flag)
	{
		if (!ft_isprint(str[i]) && str[i] != '\n')
			flag = 0;
		i++;
	}
	if (flag == 0)
	{
		errno = EIO;
		return (0);
	}
	return (1);
}

void	free_t_line(t_line *line, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(line->tab_pts);
		i++;
	}
	free(line);
}

int	vec3_in_screen(t_vec3 vec, int max_L, int max_H)
{
	int	y;
	int	x;

	x = (int)(vec.x);
	y = (int)(vec.y);
	if (((int) vec.x <= 0 || x >= max_L) || ((int) vec.y <= 0 || y >= max_H))
		return (0);
	else
		return (1);
}

void	set_window_size(t_map *map)
{
	if (map->column >= 0 && map->column < 99)
		map->win_w = 400;
	else if (map->column >= 100 && map->column < 500)
		map->win_w = 800;
	else
		map->win_w = 1200;
	if (map->line >= 0 && map->line < 99)
		map->win_h = 400;
	else if (map->line >= 100 && map->line < 500)
		map->win_h = 600;
	else
		map->win_h = 1200;
}

float	set_zoom(t_map *map)
{
	float	zoom1;
	float	zoom2;

	if (map->column >= 0 && map->column < 99)
		zoom1 = 10.0;
	else if (map->column >= 100 && map->column < 500)
		zoom1 = 5.0;
	else
		zoom1 = 1.0;
	if (map->line >= 0 && map->line < 99)
		zoom2 = 10.0;
	else if (map->line >= 100 && map->line < 500)
		zoom2 = 5.0;
	else
		zoom2 = 1.0;
	if (zoom1 > zoom2)
		return (zoom2);
	else
		return (zoom1);
}

char	*ft_free_tab(void **tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}
