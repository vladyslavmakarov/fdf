/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 03:42:36 by vmakarov          #+#    #+#             */
/*   Updated: 2017/09/05 03:42:38 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_0x(t_helper *m, t_2d *d_0, t_2d *d_1, t_draw *draw, int color)
{
	int d;
	int d1;
	int d2;
	int x;
	int y;
	int i;

	d = (draw->dy << 1) - draw->dx;
	d1 = draw->dy << 1;
	d2 = (draw->dy - draw->dx) << 1;
	mlx_pixel_put(m->mlx, m->win, d_0->x, d_0->y, color);
	x = d_0->x + draw->sx;
	y = d_0->y;
	i = 1;
	while (i <= draw->dx)
	{
		if (d > 0)
		{
			d += d2;
			y += draw->sy;
		}
		else
			d += d1;
		mlx_pixel_put(m->mlx, m->win, x, y, color + i);
		i++;
		x += draw->sx;
	}


	d_1 = NULL;
}

void	line_0y(t_helper *m, t_2d *d_0, t_2d *d_1, t_draw *draw, int color)
{
	int d;
	int d1;
	int d2;
	int x;
	int y;
	int i;

	d = (draw->dx << 1) - draw->dy;
	d1 = draw->dx << 1;
	d2 = (draw->dx - draw->dy) << 1;
	mlx_pixel_put(m->mlx, m->win, d_0->x, d_0->y, color);
	y = d_0->y + draw->sy;
	x = d_0->x;
	i = 1;
	while (i <= draw->dy)
	{
		if (d > 0)
		{
			d += d2;
			x += draw->sx;
		}
		else
			d += d1;
		mlx_pixel_put(m->mlx, m->win, x, y, color + i);
		i++;
		y += draw->sy;
	}

	d_1 = NULL;
}

void	line(t_2d *d_0, t_2d *d_1, t_helper *m, int color)
{
	t_draw	*draw;

	if (!(draw = (t_draw *)malloc(sizeof(t_draw))))
		return ;
	draw->dx = (d_1->x - d_0->x);
	if (draw->dx < 0)
		draw->dx = draw->dx * (-1);
	draw->dy = (d_1->y - d_0->y);
	if (draw->dy < 0)
		draw->dy = draw->dy * (-1);
	draw->sx = d_1->x >= d_0->x ? 1 : -1;
	draw->sy = d_1->y >= d_0->y ? 1 : -1;
	if (draw->dy <= draw->dx)
		line_0x(m, d_0, d_1, draw, color);
	else
		line_0y(m, d_0, d_1, draw, color);
}
