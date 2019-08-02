/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:29:22 by marrodri          #+#    #+#             */
/*   Updated: 2019/07/29 16:29:23 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

double	color_iter_jul(double color, double x0, double y0, t_img *st_img)
{
	double	x_sq;
	double	y_sq;
	int		i = 0;
	int		max_i = 1000;
	while((i < max_i))
	{
		x_sq = (x0 * x0) - (y0 * y0);
		y_sq = 2 * x0 * y0;
		x0 = x_sq - st_img->mouse_x;
		y0 = y_sq - st_img->mouse_y;
		if ((x0 * x0) + (y0 * y0) > 16)
			break;
		i++;
	}
	color = ft_map(i, 0, max_i, 0, 1);
	color = ft_map(sqrt(color),0,1,0,0xFFFFFF);
	if (i == max_i)
	{
		color = 0;
	}
	return (color);
}

// #define NUM_THREAD 8 small guide to multithread

void	*draw_julia(void *varg)
{
	int x;
	t_thrd_arg *st_thrd_arg;
	t_img		*st_img;

	st_thrd_arg = varg;
	x= st_thrd_arg->x;
	st_img = st_thrd_arg->st_img;
	while(x < WIN_SZ)
	{
		st_img->y = 0;
		while(st_img->y < WIN_SZ)
		{
			st_img->x0 = ft_map(x, (st_img->x_ax) * (st_img->zoom), (WIN_SZ + st_img->x_ax) * (st_img->zoom), -2, 2);
            st_img->y0 = ft_map(st_img->y, (st_img->y_ax) * (st_img->zoom), (WIN_SZ + st_img->y_ax) * (st_img->zoom), -1.5, 1.5);
            st_img->color = color_iter_jul(st_img->color, st_img->x0, st_img->y0, st_img);
            mlx_pixel_image(x, st_img);
			st_img->y++;
		}
		x += THREADS;
	}
	return NULL;
}

void multithrd_fract(t_img *st_img)
{
	pthread_t	tid[THREADS];
	t_thrd_arg	st_thrd_arg[1];
	int			i;

	i = 0;
	void *test = draw_julia;
	st_thrd_arg[0].st_img = st_img;
	while(i < THREADS)
	{
		st_thrd_arg[0].x = i;
		pthread_create(&tid[i], NULL, test, st_thrd_arg);
		pthread_join(tid[i],NULL);
		i++;
	}
	return ;
}

int	loop_jul(void *param)
{
	t_img *st_img;

	st_img = param;
	if (st_img->draw)
	{
		multithrd_fract(st_img);
		st_img->draw = 0;
		mlx_put_image_to_window(st_img->p_mlx, st_img->p_win,
			st_img->p_img, 0, 0);
	}
	return (1);
}

void    julia_set(t_img *st_img)
{
	st_img->x = 0.0;
	st_img->y = 0.0;
	st_img->x0 = 0.0;
	st_img->y0 = 0.0;
	st_img->x_ax = 0;
	st_img->y_ax = 0;
	st_img->mouse_x = 0;
	st_img->mouse_y = 0;
	st_img->color = 0xFFFFFF;
	st_img->p_win = mlx_new_window(st_img->p_mlx, WIN_SZ, WIN_SZ, "julia");
	st_img->draw = 1;
	
	multithrd_fract(st_img);

	mlx_hook(st_img->p_win, 2, 2, ft_fract_drag, (void*)st_img);
	mlx_hook(st_img->p_win, 4, (1L << 4), ft_fract_zoom, (void*)st_img);
	mlx_hook(st_img->p_win, 6, (1L << 6), ft_fract_cursor, (void*)st_img);
	mlx_loop_hook(st_img->p_mlx, loop_jul, (void*)st_img);
}
