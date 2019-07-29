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
	double		x_ax;
	double		y_ax;
	double		x;
	double		y;
	double		x0;
	double		y0;
	double		cx;
	double		cy;
	double		x_sq;
	double		color;
	double		mouse_x;
	double		mouse_y;
	int			draw;
}				t_img;

void			fract_init(t_img *st_img, char *fract);
int				mlx_pixel_image(int x, int y, char *addr, int bpp, int color);
void			draw_mand(double width, double height, double val, t_img *st_img);
int				mandelbrot_zoom(int i, int x, int y, void *param);
void			mandelbrot_set(t_img *st_img);
void			julia_set(t_img *st_img);
double			ft_map(double value, double in_min, double val_max, double out_min, double out_max);
#endif
