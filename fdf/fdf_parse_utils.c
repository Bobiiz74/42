/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parse_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:31:55 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/05/10 17:37:49 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//vérifie si le fichier en parametre à l'extension ".fdf"

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

void	set_window_size(t_map *map)
{
	if (map->column >= 0 && map->column < 99)
		map->win_w = 600;
	else if (map->column >= 100 && map->column < 500)
		map->win_w = 800;
	else
		map->win_w = 1100;
	if (map->line >= 0 && map->line < 99)
		map->win_h = 600;
	else if (map->line >= 100 && map->line < 500)
		map->win_h = 800;
	else
		map->win_h = 1100;
}

float	set_zoom(t_map *map)
{
	float	zoom1;
	float	zoom2;

	if (map->column >= 0 && map->column < 99)
		zoom1 = 11.0;
	else if (map->column >= 100 && map->column < 500)
		zoom1 = 4.0;
	else
		zoom1 = 1.0;
	if (map->line >= 0 && map->line < 99)
		zoom2 = 11.0;
	else if (map->line >= 100 && map->line < 500)
		zoom2 = 4.0;
	else
		zoom2 = 1.0;
	if (zoom1 > zoom2)
		return (zoom2);
	else
		return (zoom1);
}
