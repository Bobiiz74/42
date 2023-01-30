/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodtsch <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:30:11 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/01/30 15:41:27 by rgodtsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_var(t_vec2 *e, t_vec2 *del, t_vec2 *d, t_vec2 *inc)
{
	d->x = 2 * e->x;
	d->y = 2 * e->y;
	del->x = e->x;
	del->y = e->y;
	inc->x = 1;
	inc->y = 1;
}

void	case_dx_dy(t_vec2 e, t_vec3 p1, t_vec3 p2, t_img *data)
{
	int		i;
	t_vec2	del;
	t_vec2	d;
	t_vec2	inc;

	i = 0;
	set_var(&e, &del, &d, &inc);
	if (p1.x > p2.x)
		inc.x = -1;
	if (p1.y > p2.y)
		inc.y = -1;
	while (i <= del.x && vec3_in_screen(p1, data->win_w, data->win_h))
	{
		pixel_2img(data, p1.x, p1.y, data->color);
		i++;
		p1.x += inc.x;
		e.x -= d.y;
		if (e.x < 0)
		{
			p1.y += inc.y;
			e.x += d.x;
		}
	}
}

void	case_dy_dx(t_vec2 e, t_vec3 p1, t_vec3 p2, t_img *data)
{
	int		i;
	t_vec2	del;
	t_vec2	d;
	t_vec2	inc;

	i = 0;
	set_var(&e, &del, &d, &inc);
	if (p1.x > p2.x)
		inc.x = -1;
	if (p1.y > p2.y)
		inc.y = -1;
	while (i <= del.y && vec3_in_screen(p1, data->win_w, data->win_h))
	{
		pixel_2img(data, p1.x, p1.y, data->color);
		i++;
		p1.y += inc.y;
		e.y -= d.x;
		if (e.y < 0)
		{
			p1.x += inc.x;
			e.y += d.y;
		}
	}
}

void	draw_line(t_vec3 p1, t_vec3 p2, t_img *data)
{
	t_vec3	p1p;
	t_vec3	p2p;
	t_vec2	e;

	ft_cp_vec3(p1, &p1p);
	ft_cp_vec3(p2, &p2p);
	e.x = abs((int) p2p.x - (int) p1p.x);
	e.y = abs((int) p2p.y - (int) p1p.y);
	if (e.x > e.y)
		case_dx_dy(e, p1p, p2p, data);
	else if (e.y > e.x)
		case_dy_dx(e, p1p, p2p, data);
}
