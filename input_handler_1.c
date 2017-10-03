/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 14:24:53 by vmakarov          #+#    #+#             */
/*   Updated: 2017/09/03 14:24:55 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	***get_matrix(char **av, t_figure *h)
{
	char	*input;
	char	**temp;
	t_point	***result;
	int		y;
	int		height;

	input = read_file(av);
	if (input[0] == '\0')
	{
		ft_putstr("No data found.\n");
		exit(0);
	}
	temp = ft_strsplit(input, '\n');
	y = 0;
	height = get_mtrx_height(temp);
	if (!(result = (t_point ***)malloc(sizeof(t_point **) * (height + 1))))
		return (NULL);
	result[height] = NULL;
	while (y < height)
	{
		result[y] = get_row(temp[y], get_mrow_len(temp), y, h);
		y++;
	}
	return (result);
}

char	*read_file(char **av)
{
	int		fd;
	char	buffer[BUF_SIZE + 1];
	char	*res;
	int		i;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	res = ft_strnew(0);
	while ((i = read(fd, buffer, BUF_SIZE)) > 0)
	{
		buffer[i] = '\0';
		res = ft_strjoin(res, buffer);
	}
	if (close(fd) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	close(fd);
	return (res);
}

int		get_mtrx_height(char **d_2darray)
{
	int res;

	res = 0;
	while (d_2darray[res])
		res++;
	return (res);
}

int		get_mrow_len(char **d_2darray)
{
	int res;
	int i;
	int j;
	int temp;

	i = 0;
	temp = 0;
	while (d_2darray[i])
	{
		res = 0;
		j = 0;
		while (d_2darray[i][j] != '\0')
		{
			if (d_2darray[i][j] == ' ' && (((d_2darray[i][j + 1] >= 48
				&& d_2darray[i][j + 1] <= 57)) || d_2darray[i][j + 1] == '-'))
				res++;
			j++;
		}
		if (i == 0)
			temp = res;
		if (temp != res)
			wrong_len_exit();
		i++;
	}
	return (temp + 1);
}

void	wrong_len_exit(void)
{
	ft_putstr("Found wrong line length. Exiting.\n");
	exit(0);
}
