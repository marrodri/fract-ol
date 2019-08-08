/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:52:44 by marrodri          #+#    #+#             */
/*   Updated: 2019/07/25 18:52:45 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		close_win_x(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		esc_key(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit(1);
	return (0);
}

t_fract	*fract_setup(t_fract *fract)
{
	fract->zoom = 1;
	fract->x0 = 0.0;
	fract->y0 = 0.0;
	fract->x_ax = 0;
	fract->y_ax = 0;
	fract->color_set = 0xff0000;
	return (fract);
}

void	fract_init(t_thrd_arg *st_thrd_arg, char *argv)
{
	t_img	*st_img;
	t_map	*st_map;
	t_fract *fract;

	fract = st_thrd_arg->fract;
	st_img = st_thrd_arg->st_img;
	st_map = st_thrd_arg->st_map;
	st_img->p_mlx = mlx_init();
	st_img->p_img = mlx_new_image(st_img->p_mlx, WIN_SZ, WIN_SZ);
	st_img->addr = mlx_get_data_addr(st_img->p_img, &st_img->bpp,
		&st_img->sl, &st_img->endn);
	st_img->bpp /= 8;
	fract = fract_setup(fract);
	if (!ft_strcmp(argv, "mandelbrot"))
		mandelbrot_set(&st_thrd_arg);
	else if (!ft_strcmp(argv, "julia"))
		julia_set(&st_thrd_arg);
	// else if (!ft_strcmp(argv, "tricorn"))
	// 	tricorn_set(&st_thrd_arg);
	mlx_key_hook(st_img->p_win, esc_key, (void *)0);
	mlx_hook(st_img->p_win, 17, (1L << 17), close_win_x, (void*)0);
	mlx_loop(st_img->p_mlx);
}
