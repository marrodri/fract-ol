/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 23:04:49 by marrodri          #+#    #+#             */
/*   Updated: 2019/07/26 23:04:51 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		mlx_pixel_image(t_img *st_img)
{
	if (st_img->x < 0 || st_img->y < 0 ||
		st_img->x >= WIN_SZ || st_img->y >= WIN_SZ)
		return (0);
	*((int *)(st_img->addr + (st_img->x + st_img->y * WIN_SZ)
		* st_img->bpp)) = st_img->color;
	return (1);
}

double	ft_map(double value, double in_min, double in_max, double out_min, double out_max)
{
	return ((value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}

// void src_to_obj(double *mx0, double *my0, t_img *st_img)
// {
// 	*mx0 = (st_img->mouse_x - st_img->zoom_x)/st_img->zoom;
// 	*mx0 = (st_img->mouse_y - st_img->zoom_y)/st_img->zoom;
// }

int		ft_fract_zoom(int i, int x, int y, void *param)
{
	t_img		*st_img;
	double		mx0;
	double		my0;


	st_img = (param);
	printf("mouse_x|%f| mouse_y|%f|\n", st_img->mouse_x, st_img->mouse_y);
	printf("x|%d| y|%d|\n", x, y);
	if (i == 4)
	{
		mx0 = ((st_img->mouse_x - st_img->x0) / st_img->zoom); //zoomin
		my0 = ((st_img->mouse_y - st_img->y0) / st_img->zoom);
		printf("mx0|%f| my0|%f|\n", mx0, my0);
		st_img->zoom *= 1.1;
		mx0 = st_img->x0 + (mx0 * st_img->zoom);
		my0 = st_img->y0 + (my0 * st_img->zoom);
		st_img->x_ax += mx0 - st_img->mouse_x;
		st_img->y_ax += my0 - st_img->mouse_y;
	}
	else if (i == 5)
	{
		st_img->zoom /= 1.1;
	}
	st_img->draw = 1;
	return (1);
}

int		ft_fract_drag(int i, void *param)
{
	t_img	*st_img;

	st_img = (param);
	printf("zoom is |%f|\n", st_img->zoom);
	if (i == K_DRAG_LF)
		st_img->x_ax -= 5;
	else if (i == K_DRAG_RT)
		st_img->x_ax += 5;
	else if (i == K_DRAG_UP)
		st_img->y_ax -= 5;
	else if (i == K_DRAG_DW)
		st_img->y_ax += 5;
	st_img->draw = 1;
	return (1);
}

int		ft_fract_cursor(int x, int y, void *param)
{
	t_img	*st_img;

	st_img = (param);
	st_img->mouse_x = ft_map(x, 0, 1000, -2, 2);
	st_img->mouse_y = ft_map(y, 0, 1000, -1.5, 1.5);
	st_img->draw = 1;
	return (1);
}
