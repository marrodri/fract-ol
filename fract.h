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
# define WIN_SZ 1000
# define MS_SCROLL_UP 4
# define MS_SCROLL_DW 5
# define MS_SCROLL_LF 6
# define MS_SCROLL_RT 7
# include <pthread.h>
# include <math.h>
# include "includes/libft/libft.h"
# include "mlx.h"
# include <stdio.h>

typedef struct	s_map
{
	int			x;
	int			y;
}				t_map;

typedef	struct	s_img
{
	void		*p_mlx;
	void		*p_win;
	void		*p_img;
	char		*addr;
	int			bpp;
	int			endn;
	int			sl;
	double		zoom;
}				t_img;

typedef struct	s_app
{
	int			x_sz;
	int			y_sz;
	// void		*p_mlx;
	// 	void *p_win;
	// void *p_img;
}				t_app;

typedef struct	s_color
{
	int			color_1;
	int			color_2;
	int			color_3;
	int			color_4;
}				t_color;

typedef struct	s_manset
{
	double		x;
	double		y;
	double		x0;
	double		y0;
	double		cx;
	double		cy;
	double		x_sq;
	double		color;
	double		zoom;
}				t_manset;

typedef struct	s_julset
{
	double		ms_x;
	double		ms_y;
	double		zoom;
}				t_julset;


void			fract_init(t_img *st_img, char *fract);
int				mlx_pixel_image(int x, int y, char *addr, int bpp, int color);
void			draw_mand(double width, double height, double val, t_img *st_img, t_manset *st_manset);
int				mandelbrot_zoom(int i, int x, int y, void *param);
void mandelbrot_set(t_img *st_img, t_manset *st_manset);
double			ft_map(double value, double cur_start, double cur_end, double new_start, double new_end);
#endif
