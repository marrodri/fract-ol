/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 19:33:52 by marrodri          #+#    #+#             */
/*   Updated: 2019/08/08 19:33:53 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

double		set_xmap_m(t_map **st_map, t_img *st_img, t_fract *fract)
{
	(*st_map)->value = st_img->x;
	(*st_map)->in_min = (fract->x_ax) * (fract->zoom);
	(*st_map)->in_max = (WIN_SZ + fract->x_ax) * fract->zoom;
	(*st_map)->out_min = -2.5;
	(*st_map)->out_max = 1.;
	return ft_map(*st_map);
}

double		set_ymap_m(t_map **st_map, t_img *st_img, t_fract *fract)
{
	(*st_map)->value = st_img->y;
	(*st_map)->in_min = (fract->y_ax) * (fract->zoom);
	(*st_map)->in_max = (WIN_SZ + fract->y_ax) * fract->zoom;
	(*st_map)->out_min = -1.5;
	(*st_map)->out_max = 1.5;
	return ft_map(*st_map);
}


double	ft_map(t_map *st_map)
{
	return ((st_map->value - st_map->in_min) * (st_map->out_max -
		st_map->out_min) / (st_map->in_max - st_map->in_min) + st_map->out_min);
}
