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

int		mlx_pixel_image(t_img *st_img, t_fract *fract)
{
	if (st_img->x < 0 || st_img->y < 0 ||
		st_img->x >= WIN_SZ || st_img->y >= WIN_SZ)
		return (0);
	*((int *)(st_img->addr + (st_img->x + st_img->y * WIN_SZ)
		* st_img->bpp)) = fract->color;
	return (1);
}

int		ft_fract_zoom(int i, int x, int y, void *param)
{
	t_fract		*fract;

	x = 0;
	y = 0;
	fract = (param);
	if (i == 4)
		fract->zoom *= 1.1;
	else if (i == 5)
		fract->zoom /= 1.1;
	fract->draw = 1;
	return (1);
}

int		ft_fract_drag(int i, void *param)
{
	t_fract	*fract;

	fract = (param);
	if (i == K_DRAG_LF)
		fract->x_ax -= 5;
	else if (i == K_DRAG_RT)
		fract->x_ax += 5;
	else if (i == K_DRAG_UP)
		fract->y_ax -= 5;
	else if (i == K_DRAG_DW)
		fract->y_ax += 5;
	fract->draw = 1;
	return (1);
}

int		ft_fract_cursor(int x, int y, void *param)
{
	t_fract	*fract;

	fract = (param);
	fract->mouse_x = x * 4. / 1000. - 2.;
	fract->mouse_y = y * 3. / 1000. - 1.5;
	fract->draw = 1;
	return (1);
}
