/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:27:08 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/01/30 16:31:32 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_cp_vec3(t_vec3 point, t_vec3 *new_vec)
{
	new_vec->x = point.x;
	new_vec->y = point.y;
	new_vec->z = point.z;
}

void	print_vec3(t_vec3 vec)
{
	ft_printf("(%d,", vec.x);
	ft_printf("%d,", vec.y);
	ft_printf("%d)\n", vec.z);
}

int	ft_val_in_r(int v, int min, int max)
{
	if (v >= min && v <= max)
		return (1);
	else
		return (0);
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
