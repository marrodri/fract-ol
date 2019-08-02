/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 22:16:31 by marrodri          #+#    #+#             */
/*   Updated: 2019/07/26 23:12:17 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

double		color_iter_mand(double color, double x0, double y0, double cx, double cy)
{
	double	x_sq;
	double	y_sq;
	int		i;
	int		max_i;

	i = 0;
	max_i = 1000;
	while (i < max_i)
	{
		x_sq = (x0 * x0) - (y0 * y0);
		y_sq = 2 * x0 * y0;
		x0 = x_sq + cx;
		y0 = y_sq + cy;
		if ((x0 * x0) + (y0 * y0) > 16)
			break ;
		i++;
	}
	color = ft_map(i, 0, max_i, 0, 1);
	color = ft_map(sqrt(color), 0, 1, 0, 0x80ff00);
	if (i == max_i)
	{
		color = 23;
	}
	return (color);
}

void		*draw_mand(void *varg)
{
	int x;
	double cx;
	double cy;
	t_thrd_arg *st_thrd_arg;
	t_img *st_img;

	st_thrd_arg = varg;
	x = st_thrd_arg->x;
	st_img = st_thrd_arg->st_img;
	while (x < WIN_SZ)
	{
		st_img->y = 0;
		while (st_img->y < WIN_SZ)
		{
			// st_map->in_min = st_img->x_ax * (st_img->zoom);
			// st_map->in_max = (WIN_SZ + st_img->x_ax) * st_img->zoom;
			st_img->x0 = ft_map(x, (st_img->x_ax) * (st_img->zoom), (WIN_SZ + st_img->x_ax) * st_img->zoom, -2.5, 1);
			st_img->y0 = ft_map(st_img->y, (st_img->y_ax) * (st_img->zoom), (WIN_SZ + st_img->y_ax) * st_img->zoom, -1.5, 1.5);
			cx = st_img->x0;
			cy = st_img->y0;
			st_img->color = color_iter_mand(st_img->color, st_img->x0, st_img->y0, cx, cy);
			mlx_pixel_image(x, st_img);
			st_img->y++;
		}
		x += THREADS;
	}
	return NULL;
}

void multithrd_fract_m(t_img *st_img)
{
	pthread_t	tid[THREADS];
	t_thrd_arg	st_thrd_arg[1];
	int			i;

	i = 0;
	void *test = draw_mand;
	st_thrd_arg[0].st_img = st_img;
	while(i < THREADS)
	{
		st_thrd_arg[0].x = i;
		pthread_create(&tid[i], NULL, test, st_thrd_arg);
		pthread_join(tid[i],NULL);
		i++;
	}

	// free(t_thrd_arg);
	return ;
}

int			loop_mand(t_img *st_img)
{
	if (st_img->draw)
	{
		multithrd_fract_m(st_img);
		st_img->draw = 0;
		mlx_put_image_to_window(st_img->p_mlx, st_img->p_win,
			st_img->p_img, 0, 0);
	}
	return (1);
}

void		mandelbrot_set(t_img *st_img, t_map *st_map)
{
	st_map = NULL;
	st_img->x0 = 0.0;
	st_img->y0 = 0.0;
	st_img->x_ax = 0;
	st_img->y_ax = 0;
	st_img->color = 0x80ff00;
	st_img->p_win = mlx_new_window(st_img->p_mlx, WIN_SZ, WIN_SZ, "mand");
	st_img->draw = 1;
	// st_map->in_min = st_img->x_ax * (st_img->zoom);
	// st_map->in_max = (WIN_SZ + st_img->x_ax) * st_img->zoom;
	
	
	// draw_mand(st_img);
	multithrd_fract_m(st_img);
	mlx_hook(st_img->p_win, 2, 2, ft_fract_drag, (void*)st_img);
	mlx_hook(st_img->p_win, 4, (1L << 4), ft_fract_zoom, (void*)st_img);
	mlx_loop_hook(st_img->p_mlx, loop_mand, st_img);
}
