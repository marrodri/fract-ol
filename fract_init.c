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

int		mouse_move(int x, int y, void *param)
{
	printf("x|%d|, y|%d|\n", x, y);
	return (0);
}

void	fract_init(t_img *st_img, char *fract)
{
	t_manset *st_manset;
	t_julset *st_julset;

	st_manset = malloc(sizeof(t_manset));
	st_julset = malloc(sizeof(t_julset));
	st_img->zoom = 0;
	st_img->p_mlx = mlx_init();
	st_img->p_img = mlx_new_image(st_img->p_mlx, WIN_SZ, WIN_SZ);
	st_img->addr = mlx_get_data_addr(st_img->p_img, &st_img->bpp,
		&st_img->sl, &st_img->endn);
	st_img->bpp /= 8;
	if (!ft_strcmp(fract, "mandelbrot"))
	{
		mandelbrot_set(st_img, st_manset);
	}
	mlx_key_hook(st_img->p_win, esc_key, (void *)0);
	mlx_hook(st_img->p_win, 17, (1L << 17), close_win_x, (void*)0);
	mlx_loop(st_img->p_mlx);
}
