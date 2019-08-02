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
	int		max_i = 256;

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

void	*draw_julia(void *arg)
{
	t_img			*st_img;
	t_thread_arg	*targ;
	int		y;
	double		x0;
	double		y0;
	int		color;

	targ = arg;
	st_img = targ->st_img;
	while(targ->x < WIN_SZ)
	{
		y = 0;
		while(y < WIN_SZ)
		{
			x0 = ft_map(targ->x, (st_img->x_ax) * (st_img->zoom) * 0.1, (WIN_SZ + st_img->x_ax) * (st_img->zoom), -2, 2);
            y0 = ft_map(y, (st_img->y_ax) * (st_img->zoom) * 0.1, (WIN_SZ + st_img->y_ax) * (st_img->zoom), -1.5, 1.5);
            color = color_iter_jul(color, x0, y0, st_img);
            mlx_pixel_image(targ->x, y, color, st_img);
			y++;
		}
		targ->x += NUM_THREAD;
	}
	return NULL;
}


void multithrd_fract(t_img *st_img)
{
	pthread_t		st_thrd[NUM_THREAD];
	t_thread_arg	st_thrd_arg[NUM_THREAD];
	int			i;

	i = 0;
	while (i < NUM_THREAD)
	{
		st_thrd_arg[i].st_img = st_img;
		st_thrd_arg[i].x = i;
		pthread_create(&st_thrd[i], NULL, draw_julia, &st_thrd_arg[i]);
		pthread_join(st_thrd[i], NULL);
		// st_img->x = 1;
		// pthread_create(&st_thrd->tid1, NULL, draw_julia, st_img);
		// pthread_join(st_thrd->tid1, NULL);
		// st_img->x = 2;
		// pthread_create(&st_thrd->tid2, NULL, draw_julia, st_img);
		// pthread_join(st_thrd->tid2, NULL);
		// st_img->x = 3;
		// pthread_create(&st_thrd->tid3, NULL, draw_julia, st_img);
		// pthread_join(st_thrd->tid3, NULL);
		// st_img->x = 4;
		// pthread_create(&st_thrd->tid4, NULL, draw_julia, st_img);
		// pthread_join(st_thrd->tid4, NULL);
		// st_img->x = 5;
		// pthread_create(&st_thrd->tid5, NULL, draw_julia, st_img);
		// pthread_join(st_thrd->tid5, NULL);
		// st_img->x = 6;
		// pthread_create(&st_thrd->tid6, NULL, draw_julia, st_img);
		// pthread_join(st_thrd->tid6, NULL);
		// st_img->x = 7;
		// pthread_create(&st_thrd->tid7, NULL, draw_julia, st_img);
		// pthread_join(st_thrd->tid7, NULL);
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
	// pthread_t jul_id;
	// t_thrd *st_thrd;
	// st_thrd = malloc(sizeof(t_thrd));

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
	
	multithrd_fract( st_img);
	// draw_julia(1000, 1000, st_img);

	mlx_hook(st_img->p_win, 2, 2, ft_fract_drag, (void*)st_img);
	mlx_hook(st_img->p_win, 4, (1L << 4), ft_fract_zoom, (void*)st_img);
	mlx_hook(st_img->p_win, 6, (1L << 6), ft_fract_cursor, (void*)st_img);
	mlx_loop_hook(st_img->p_mlx, loop_jul, (void*)st_img);
}
