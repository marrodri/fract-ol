/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:40:34 by marrodri          #+#    #+#             */
/*   Updated: 2019/07/24 13:40:35 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H
# define WIN_SZ		1000
# define MAX_I		256
# define K_DRAG_UP	126
# define K_DRAG_DW	125
# define K_DRAG_LF	123
# define K_DRAG_RT	124
# define THREADS	8
# include <pthread.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx.h"
# include <stdio.h>

typedef	struct	s_img
{
	int			x;
	int			y;
	void		*p_mlx;
	void		*p_win;
	void		*p_img;
	char		*addr;
	int			bpp;
	int			endn;
	int			sl;
}				t_img;

typedef struct	s_map_x
{
	double		value;
	double		out_min;
	double		out_max;
	double		in_min;
	double		in_max;
}				t_map;

typedef struct	s_fract
{
	double		zoom;
	double		x_ax;
	double		y_ax;
	double		x0;
	double		y0;
	int			color;
	double		mouse_x;
	double		mouse_y;
	int			draw;
}				t_fract;

typedef struct	s_thrd_arg
{
	t_fract		*fract;
	t_img		*st_img;
	t_map		*st_map;
}				t_thrd_arg;

void			fract_init(t_thrd_arg *st_thrd_arg, char *fract);
int				mlx_pixel_image(t_img *st_img, t_fract *fract);
int				ft_fract_zoom(int i, int x, int y, void *param);
int				ft_fract_drag(int i, void *param);
int				ft_fract_cursor(int x, int y, void *param);
void			mandelbrot_set(t_thrd_arg **st_thrd_arg);
void			julia_set(t_thrd_arg **st_thrd_arg);
void			tricorn_set(t_thrd_arg **st_thrd_arg);
void			*draw_julia(void *varg);
void			*draw_mand(void *varg);
double			ft_map(double value, double in_min, double in_max,
		double out_min, double out_max);
#endif
