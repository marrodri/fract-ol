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

double		color_iter_mand(double color, t_fract *fract)
{
	double	x_sq;
	double	y_sq;
	double	cx;
	double	cy;
	int		i;

	i = 0;
	cx = fract->x0;
	cy = fract->y0;
	while (i < MAX_I)
	{
		x_sq = (fract->x0 * fract->x0) - (fract->y0 * fract->y0);
		y_sq = 2 * fract->x0 * fract->y0;
		fract->x0 = x_sq + cx;
		fract->y0 = y_sq + cy;
		if ((fract->x0 * fract->x0) + (fract->y0 * fract->y0) > 16)
			break ;
		i++;
	}
	color = ft_map(i, 0, MAX_I, 0, 1);
	color = ft_map(sqrt(color), 0, 1, 0, 0x80ff00);
	if (i == MAX_I)
		color = 0;
	return (color);
}

void		*draw_mand(void *varg)
{
	t_thrd_arg	*st_thrd_arg;
	t_img		*st_img;
	t_map		*st_map;
	t_fract		*fract;

	st_thrd_arg = varg;
	st_img = st_thrd_arg->st_img;
	st_map = st_thrd_arg->st_map;
	fract = st_thrd_arg->fract;
	while (st_img->x < WIN_SZ)
	{
		st_img->y = 0;
		while (st_img->y < WIN_SZ)
		{
			fract->x0 = ft_map(st_img->x, (fract->x_ax) * (fract->zoom),
					(WIN_SZ + fract->x_ax) * fract->zoom, -2.5, 1);
			fract->y0 = ft_map(st_img->y, (fract->y_ax) * (fract->zoom),
					(WIN_SZ + fract->y_ax) * fract->zoom, -1.5, 1.5);
			fract->color = color_iter_mand(fract->color, fract);
			mlx_pixel_image(st_img, fract);
			st_img->y++;
		}
		st_img->x += THREADS;
	}
	return (NULL);
}

void		thread_mand(t_thrd_arg *st_thrd_arg)
{
	pthread_t	tid[THREADS];
	int			i;

	i = 0;
	while (i < THREADS)
	{
		st_thrd_arg->st_img->x = i;
		pthread_create(&tid[i], NULL, draw_mand, st_thrd_arg);
		pthread_join(tid[i], NULL);
		i++;
	}
	return ;
}

int			loop_mand(t_thrd_arg *st_thrd_arg)
{
	t_img	*st_img;
	t_fract	*fract;

	fract = st_thrd_arg->fract;
	st_img = st_thrd_arg->st_img;
	if (fract->draw)
	{
		thread_mand(st_thrd_arg);
		fract->draw = 0;
		mlx_put_image_to_window(st_img->p_mlx, st_img->p_win,
			st_img->p_img, 0, 0);
	}
	return (1);
}

void		mandelbrot_set(t_thrd_arg **st_thrd_arg)
{
	t_img	*st_img;
	t_fract	*fract;

	st_img = (*st_thrd_arg)->st_img;
	fract = (*st_thrd_arg)->fract;
	st_img->p_win = mlx_new_window(st_img->p_mlx, WIN_SZ, WIN_SZ, "mand");
	fract->draw = 1;
	thread_mand(*st_thrd_arg);
	mlx_hook(st_img->p_win, 2, 2, ft_fract_drag, (void*)fract);
	mlx_hook(st_img->p_win, 4, (1L << 4), ft_fract_zoom, (void*)fract);
	mlx_hook(st_img->p_win, 6, (1L << 6), ft_fract_cursor, (void*)fract);
	mlx_loop_hook(st_img->p_mlx, loop_mand, (*st_thrd_arg));
}
