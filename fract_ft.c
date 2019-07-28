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

int		mlx_pixel_image(int x, int y, char *addr, int bpp, int color)
{
	if (x < 0 || y < 0 || x >= WIN_SZ || y >= WIN_SZ)
		return (0);
	*((int *)(addr + (x + y * WIN_SZ) * bpp)) = color;
	return (1);
}

double	ft_map(double value, double in_min, double in_max, double out_min, double out_max)
{
	return((value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min);
}
