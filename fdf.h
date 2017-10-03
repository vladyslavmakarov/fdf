/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 18:59:23 by vmakarov          #+#    #+#             */
/*   Updated: 2017/08/30 18:59:25 by vmakarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H
# include "./libft/libft.h"
# include "./minilibx_macos/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <math.h>
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"
# define BUF_SIZE	13

typedef struct		s_3d
{
	double				x;
	double				y;
	double				z;
}					t_3d;

typedef struct		s_2d
{
	double				x;
	double				y;
}					t_2d;

typedef struct		s_point
{
	t_2d			*d_2;
	t_3d			*d_3;
	signed int		sign;
//	char			*color;
//	int 			*color;
}					t_point;

typedef struct		s_figure
{
	double			a;
	double			b;
	double			t;
	int				vert;
	int				hor;
	double			scale;
}					t_figure;

typedef struct		s_helper
{
	void			*mlx;
	void			*win;
	t_figure		*parameters;
	t_point			***matrix;
}					t_helper;

typedef	struct 		s_draw
{
	int 			dx;
	int 			dy;
	int 			sx;
	int 			sy;
}					t_draw;
/*
**		EVENTS_1.C
*/

int					key_inputs(int keycode, t_helper *m);
void				move(int k, t_helper *m);
void				scale(int k, t_helper *m);
void				rotate(int k, t_helper *m);
void				ft_finish(int k, t_helper *m);

/*
**		EVENTS_2.C
*/

void				height(int k, t_helper *m);
void				scale_z(int k, t_helper *m);

/*
**		MAIN.C
**	gcc main.c input_handler_1.c line.c input_handler_2.c events_1.c events_2.c fdf.h -L minilibx_macos ./libft/libft.a  -lmlx -framework OpenGL -framework AppKit -I minilibx_macos -I libft
*/

t_figure			*parameters_init();
void				draw_figure(t_helper *m);
void				line(t_2d *d_0, t_2d	*d_1, t_helper *m,
													int color);

/*
**		INPUT_HANDLER_1.C
*/

t_point				***get_matrix(char **av, t_figure *h);
char				*read_file(char **av);
int					get_mtrx_height(char **d_2darray);
int					get_mrow_len(char **d_2darray);
void				wrong_len_exit();

/*
**		INPUT_HANDLER_2.C
*/

t_point				**get_row(char *s, int len, int y, t_figure *h);
t_point				*get_inputs(char *s, int y, int x, t_figure *h);
t_point				*transform_2d(t_point *i, t_figure *h);
int					is_color(char *s);

/*
**		LINE.C
*/

void				line(t_2d *d_0, t_2d *d_1, t_helper *m, int color);
void				line_0x(t_helper *m, t_2d *d_0, t_2d *d_1, t_draw *draw, int color);
void				line_0y(t_helper *m, t_2d *d_0, t_2d *d_1, t_draw *draw, int color);

#endif
