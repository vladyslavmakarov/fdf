/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 03:17:26 by vmakarov          #+#    #+#             */
/*   Updated: 2017/09/05 03:17:29 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_inputs(int keycode, t_helper *m)
{
	if (keycode > 122 && keycode < 127)
		move(keycode, m);
	else if (keycode == 24 || keycode == 27)
		scale(keycode, m);
//	else if (keycode > 2 || keycode < 18)
//		colorize(keycode, matrix, mlx, win);
	else if (keycode > 31 && keycode < 47)
		rotate(keycode, m);
	else if (keycode == 12 || keycode == 13)
		height(keycode, m);
	else if (keycode == 6 || keycode == 7)
		scale_z(keycode, m);
	else if (keycode == 53)
		ft_finish(keycode, m);
	printf(GREEN"Vert is: %d\nHor is: %d\nScale is: %f\nAlpha is: %f\nBeta is: %f\nTeta is: %f\n\nKeycode is: %i\n\nx_c is: %i\ny_c is: %i\nz_min is: %i\nz_max is: %i\n"RESET"\n", m->parameters->vert, m->parameters->hor, m->parameters->scale, 
	m->parameters->a, m->parameters->b, m->parameters->t, keycode, m->parameters->x_c, m->parameters->y_c, m->parameters->z_min, m->parameters->z_max);
	return (0);
}

void	move(int k, t_helper *m)
{
	int i;
	int j;

	i = 0;
	if (k == 123)
		m->parameters->hor -= 20;
	else if (k == 124)
		m->parameters->hor += 20;
	else if (k == 125)
		m->parameters->vert += 20;
	else if (k == 126)
		m->parameters->vert -= 20;
	while (m->matrix[i])
	{
		j = 0;
		while (m->matrix[i][j])
		{
			transform_2d(m->matrix[i][j], m->parameters);
			j++;
		}
		i++;
	}
	mlx_clear_window(m->mlx, m->win);
	draw_figure(m);
}

void	scale(int k, t_helper *m)
{
	int i;
	int j;

	i = 0;
	if (k == 24)
		m->parameters->scale *= 1.01;
	if (k == 27)
		m->parameters->scale /= 1.01;
	while (m->matrix[i])
	{
		j = 0;
		while (m->matrix[i][j])
		{
			transform_2d(m->matrix[i][j], m->parameters);
			j++;
		}
		i++;
	}
	mlx_clear_window(m->mlx, m->win);
	draw_figure(m);
}

void	rotate(int k, t_helper *m)
{
	int i;
	int j;

	i = -1;
	if (k == 32)
		m->parameters->t -= 0.08;
	else if (k == 34)
		m->parameters->t += 0.08;
	else if (k == 38)
		m->parameters->b -= 0.08;
	else if (k == 40)
		m->parameters->b += 0.08;
	else if (k == 45)
		m->parameters->a -= 0.08;
	else if (k == 46)
		m->parameters->a += 0.08;
	while (m->matrix[++i])
	{
		j = -1;
		while (m->matrix[i][++j])
			transform_2d(m->matrix[i][j], m->parameters);
	}
	mlx_clear_window(m->mlx, m->win);
	draw_figure(m);
}

void	ft_finish(int k, t_helper *m)
{
	if (k != 53)
		return ;
	mlx_clear_window(m->mlx, m->win);
	mlx_destroy_window(m->mlx, m->win);
	exit(0);
}
