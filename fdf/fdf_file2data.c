/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_file2data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:34:55 by rgodtsch          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/02/06 15:11:11 by rgodtsch         ###   ########.fr       */
=======
/*   Updated: 2023/02/04 15:46:02 by rgodtsch         ###   ########.fr       */
>>>>>>> 7dbaf72d18d961799bb466ee7e244ffa61e6f078
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main_parser(char *path, t_map *map)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("fdf_file2data.c - main_parser (fd):");
		return (0);
	}
	if (!map_parser(fd, map))
	{
		perror("fdf_file2data.c - map_parser (fd):");
		return (0);
	}
	close (fd);
	set_window_size(map);
	return (1);
}

int	map_parser(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	if (!check_line(line))
	{
		perror("fdf_file2data.c - checkline");
		free(line);
		return (0);
	}	
	get_first_info_parser(line, map);
	line = get_next_line(fd);
	while (line)
	{
		if (!new_line_2_tab(line, map))
		{
			free(line);
			return (0);
		}
		line = get_next_line(fd);
		map->line++;
	}
	return (1);
}

void	get_first_info_parser(char *line, t_map *map)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(line, ' ');
	while (tab[i])
		i++;
	map->column = i;
	map->line = 0;
	map->max_h = 0;
	map->tab_line = get_next_pts_line(map, tab);
	map->line++;
	ft_free_tab((void **)tab, i);
	free(line);
}

t_line	*get_next_pts_line(t_map *map, char **tab)
{
	int		i;
	t_vec3	*dt_pts;
	t_line	*new_tab;

	new_tab = malloc(sizeof(*new_tab) * (map->line + 1));
	dt_pts = malloc(sizeof(*dt_pts) * map->column);
	i = 0;
	if (map->line)
	{
		while (i < map->line)
		{
			new_tab[i] = map->tab_line[i];
			i++;
		}
		free(map->tab_line);
	}
	i = -1;
	while (++i < map->column)
	{
		dt_pts[i].x = (float) i;
		dt_pts[i].y = (float) map->line;
		dt_pts[i].z = (float) ft_atoi(tab[i]);
	}
	new_tab[map->line].tab_pts = dt_pts;
	return (new_tab);
}

int	new_line_2_tab(char *line, t_map *map)
{
	char	**tab;
	int		i;

	if (!check_line(line))
	{
		perror("fdf_file2data.c - checkline");
		free(line);
		return (0);
	}
	tab = ft_split(line, ' ');
	i = 0;
	while (tab[i])
		i++;
	if (i < map->column)
	{
		ft_free_tab((void **)tab, i);
		errno = EINVAL;
		perror("fdf_file2data.c - new_line_2_tab");
		return (0);
	}
	map->tab_line = get_next_pts_line(map, tab);
	free(line);
	ft_free_tab((void **)tab, i);
	return (1);
}
