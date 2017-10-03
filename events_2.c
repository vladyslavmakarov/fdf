/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 03:17:47 by vmakarov          #+#    #+#             */
/*   Updated: 2017/09/05 03:17:49 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	height(int k, t_helper *m)
{
	int i;
	int j;
	int f;

	i = -1;
	f = 0;
	while (m->matrix[++i])
	{
		j = -1;
		while (m->matrix[i][++j])
		{
			if (m->matrix[i][j]->sign == 1 && k == 12)
				m->matrix[i][j]->d_3->z -= 1;
			if (m->matrix[i][j]->sign == -1 && k == 12)
				m->matrix[i][j]->d_3->z += 1;
			if (m->matrix[i][j]->sign == 1 && k == 13)
				m->matrix[i][j]->d_3->z += 1;
			if (m->matrix[i][j]->sign == -1 && k == 13)
				m->matrix[i][j]->d_3->z -= 1;
			transform_2d(m->matrix[i][j], m->parameters);
		}
	}
	mlx_clear_window(m->mlx, m->win);
	draw_figure(m);
}

void	scale_z(int k, t_helper *m)
{
	int i;
	int j;
	int f;

	i = 0;
	f = 0;
	while (m->matrix[i])
	{
		j = 0;
		while (m->matrix[i][j])
		{
			if (k == 6)
				m->matrix[i][j]->d_3->z /= 1.2;
			else if (k == 7)
				m->matrix[i][j]->d_3->z *= 1.2;
			transform_2d(m->matrix[i][j], m->parameters);
			j++;
		}
		i++;
	}
	mlx_clear_window(m->mlx, m->win);
	draw_figure(m);
}
