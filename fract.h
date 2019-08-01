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
# define K_DRAG_UP 126
# define K_DRAG_DW 125
# define K_DRAG_LF 123
# define K_DRAG_RT 124
# include <pthread.h>
# include <math.h>
# include "libft/libft.h"
# include "mlx.h"
# include <stdio.h>

typedef	struct	s_img
{
	int		x;
	int		y;
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
	double		x0;
	double		y0;
	int		color;
	double		mouse_x;
	double		mouse_y;
	int			draw;
}				t_img;

typedef struct	s_map
{
	double		out_min;
	double		out_max;
}				t_map;

void			fract_init(t_img *st_img, t_map *st_map, char *fract);
int				mlx_pixel_image(t_img *st_img);
double			ft_map(double value, double in_min, double val_max, double out_min, double out_max);
int				ft_fract_zoom(int i, void *param);
int				ft_fract_drag(int i, void *param);
int				ft_fract_cursor(int x, int y, void *param);
void			mandelbrot_set(t_img *st_img, t_map *st_map);
void			julia_set(t_img *st_img);
void			tricorn_set(t_img *st_img, t_map *st_map);
#endif
