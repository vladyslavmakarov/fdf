/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 14:47:52 by vmakarov          #+#    #+#             */
/*   Updated: 2017/09/03 14:47:54 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**get_row(char *s, int len, int y, t_figure *h)
{
	t_point		**result;
	char		**temp;
	int			x;

	x = 0;
	if (!(result = (t_point **)malloc(sizeof(t_point *) * (len + 1))))
		return (NULL);
	result[len] = NULL;
	temp = ft_strsplit(s, ' ');
	while (x < len)
	{
		result[x] = get_inputs(temp[x], y, x, h);
		if (result[x]->d_3->z < 0)
			result[x]->sign = -1;
		else if (result[x]->d_3->z > 0)
			result[x]->sign = 1;
		else
			result[x]->sign = 0;
		x++;
	}
	return (result);
}

t_point	*get_inputs(char *s, int y, int x, t_figure *h)
{
	t_point	*result;
	int		i;
	int		check;
	char	**helper;

	if (!(result = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	if (!(result->d_2 = (t_2d *)malloc(sizeof(t_2d))))
		return (NULL);
	if (!(result->d_3 = (t_3d *)malloc(sizeof(t_3d))))
		return (NULL);
	i = 0;
	check = is_color(s);
	result->d_3->x = (double)x;
	result->d_3->y = (double)y;
	if (check == 0)
		result->d_3->z = ft_atoi(s);
	else
	{
		helper = ft_strsplit(s, ',');
		result->d_3->z = (double)ft_atoi(helper[0]);
		ft_strdel(helper);
	}
	result = transform_2d(result, h);
	return (result);
}

t_point	*transform_2d(t_point *i, t_figure *h)
{
	i->d_2->x = (cos(h->a) * cos(h->b) * i->d_3->x +
	(-sin(h->a) * cos(h->t) + cos(h->a) * sin(h->b) * sin(h->t)) * i->d_3->y +
	((-sin(h->a)) * (-sin(h->t)) + cos(h->a) * sin(h->b)
		* cos(h->t)) * i->d_3->z) * h->scale + h->hor;
	i->d_2->y = (sin(h->a) * cos(h->b) * i->d_3->x +
	(cos(h->a) * cos(h->t) + sin(h->a) * sin(h->b) * sin(h->t)) * i->d_3->y +
	(cos(h->a) * (-sin(h->t)) + sin(h->a) * sin(h->b)
		* cos(h->t)) * i->d_3->z) * h->scale + h->vert;
	return (i);
}

int		is_color(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ',' && s[i + 1] == '0' && s[i + 2] == 'x' &&
			s[i + 9] == '\0')
			return (i);
		if ((s[i] < 48 || s[i] > 57) && s[i] != '-')
			s[i] = 48;
		i++;
	}
	return (0);
}
