
#include "fract.h"

double		color_iter_tri(double color, double x0, double y0, double cx, double cy)
{
	double	x_sq;
	double	y_sq;
	int		i;
	int		max_i;

	i = 0;
	max_i = 1000;
	while (i < max_i)
	{
		x_sq = (x0 * x0) - (y0 * y0);
		y_sq = -2 * x0 * y0;
		x0 = x_sq + cx;
		y0 = y_sq + cy;
		if ((x0 * x0) + (y0 * y0) > 16)
			break ;
		i++;
	}
	color = ft_map(i, 0, max_i, 0, 1);
	color = ft_map(sqrt(color), 0, 1, 0, 0x80ff00);
	if (i == max_i)
	{
		color = 23;
	}
	return (color);
}

void		draw_tri(t_img *st_img)
{
	double cx;
	double cy;

	st_img->x = 0;
	while (st_img->x < WIN_SZ)
	{
		st_img->y = 0;
		while (st_img->y < WIN_SZ)
		{
			// st_map->in_min = st_img->x_ax * (st_img->zoom);
			// st_map->in_max = (WIN_SZ + st_img->x_ax) * st_img->zoom;
			st_img->x0 = ft_map(st_img->x, st_img->x_ax * (st_img->zoom), (WIN_SZ + st_img->x_ax) * st_img->zoom, -2.0, 1.5);
			st_img->y0 = ft_map(st_img->y, st_img->y_ax * (st_img->zoom), (WIN_SZ + st_img->y_ax) * st_img->zoom, -1.5, 1.5);
			cx = st_img->x0;
			cy = st_img->y0;
			st_img->color = color_iter_tri(st_img->color, st_img->x0, st_img->y0, cx, cy);
			mlx_pixel_image(st_img);
			st_img->y++;
		}
		st_img->x++;
	}
}

int			loop_tri(t_img *st_img)
{
	if (st_img->draw)
	{
		draw_tri(st_img);
		st_img->draw = 0;
		mlx_put_image_to_window(st_img->p_mlx, st_img->p_win,
			st_img->p_img, 0, 0);
	}
	return (1);
}

void		tricorn_set(t_img *st_img, t_map *st_map)
{
	st_img->x0 = 0.0;
	st_img->y0 = 0.0;
	st_img->x_ax = 0;
	st_img->y_ax = 0;
	st_img->color = 0x80ff00;
	st_img->p_win = mlx_new_window(st_img->p_mlx, WIN_SZ, WIN_SZ, "mand");
	st_img->draw = 1;
	// st_map->in_min = st_img->x_ax * (st_img->zoom);
	// st_map->in_max = (WIN_SZ + st_img->x_ax) * st_img->zoom;
	draw_tri(st_img);
	mlx_hook(st_img->p_win, 2, 2, ft_fract_drag, (void*)st_img);
	mlx_hook(st_img->p_win, 4, (1L << 4), ft_fract_zoom, (void*)st_img);
	mlx_loop_hook(st_img->p_mlx, loop_tri, st_img);
}
