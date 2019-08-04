
#include "fract.h"

t_map *set_color1(t_map *st_map, int i)
{
	st_map->value = i;
	st_map->in_min = 0;
	st_map->in_max = MAX_I;
	st_map->out_min = 0;
	st_map->out_max = 1;
	return (st_map);
}

t_map *set_color2(t_map *st_map, double color)
{
	st_map->value = sqrt(color);
	st_map->in_min = 0;
	st_map->in_max = 1;
	st_map->out_min = 0;
	st_map->out_max = 0x80ff00;
	return (st_map);
}

t_map *set_mapx(t_img *st_img, t_map *st_map)
{
	st_map->value = st_img->x;
	st_map->in_min = st_img->x_ax * st_img->zoom;
	st_map->in_max = (WIN_SZ + st_img->x_ax) * st_img->zoom;
	st_map->out_min = -2.5;
	st_map->out_max = 1;
	return (st_map);
}

t_map *set_mapy(t_img *st_img, t_map *st_map)
{
	st_map->value = st_img->y;
	st_map->in_min = (st_img->y_ax) * (st_img->zoom);
	st_map->in_max = (WIN_SZ + st_img->y_ax) * st_img->zoom;
	st_map->out_min = -1.5;
	st_map->out_max = 1.5;
	return (st_map);
}

// double	ft_map(t_map *st_map)
// {
// 	return ((st_map->value - st_map->in_min) * (st_map->out_max - st_map->out_min) /
// 	(st_map->in_max - st_map->in_min) + st_map->out_min);
// }
