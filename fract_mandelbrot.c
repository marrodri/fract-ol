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

//TODO implement properly the zoom function
int		mandelbrot_zoom(int i, int x, int y, void *param)
{
	t_img		*st_img;
	printf("input i for mandelbrot|%d|\n",i);
	st_img = (param);
	st_img->x = 0.0;
	st_img->y = 0.0;
	st_img->x0 = 0.0;
	st_img->y0 = 0.0;
	st_img->cx = 0.0;
	st_img->cy = 0.0;
	st_img->color = 0;
	if (i == 5)
	{
		st_img->zoom *= 1.1;
		st_img->draw = 1;
	}
	else if (i == 4)
	{
		st_img->zoom /= 1.1;
		st_img->draw = 1;
	}
	return (1);
}

int		mandelbrot_drag(int i, void *param)
{
	t_img	*st_img;
	st_img = (param);
	printf("keyboard input code i = |%d|\n", i);
	
	if(i == 123) //left = 123
	{
		st_img->x_ax -= 5 * st_img->zoom;
	}
	else if(i == 124) //right = 124
	{
		st_img->x_ax += 5 * st_img->zoom;
	}
	else if(i == 126) //up = 126
	{
		st_img->y_ax -= 15 * st_img->zoom;
	}
	else if(i == 125) //down = 125
	{
		st_img->y_ax += 15 * st_img->zoom;
	}
	st_img->draw = 1;
	return 1;
}

double	color_iter_mand(double color, double x0, double y0, double cx, double cy, double val)
{
	double	x_sq;
	double	y_sq;
	int		i = 0;
	int		max_i = 500;
	while((i < max_i))
	{
		x_sq = (x0 * x0) - (y0 * y0);
		y_sq = 2 * x0 * y0;
		x0 = x_sq + cx;
		y0 = y_sq + cy;
		if ((x0 * x0) + (y0 * y0) > 16)
			break;
		i++;
	}
	color = ft_map(i, 0, max_i, 0, 1);
	color = ft_map(sqrt(color),0,1,0,0x80ff00);
	if (i == max_i)
	{
		color = 23;
	}
	return (color);
}

void	draw_mand(double width, double height, double val, t_img *st_img)
{
	int		i;
	int		max_i; //iterations

	printf("new change in mandelbrot\n");
	printf("x_ax = |%f|, y_ax = |%f|\n", st_img->x_ax, st_img->y_ax);
	for(st_img->x =0; st_img->x < width; st_img->x++)
    {
        for(st_img->y =0; st_img->y < height; st_img->y++)
        {
			// st_img->x0 = ft_map(st_img->x, (st_img->x_ax - st_img->zoom * width), (st_img->zoom * width + st_img->x_ax), -2.5, 1);
            // st_img->y0 = ft_map(st_img->y, (st_img->y_ax - st_img->zoom * height), (st_img->zoom * height + st_img->y_ax), -1.5, 1.5);
			//fix this to zoom to mouse pointer
            st_img->x0 = ft_map(st_img->x, st_img->x_ax * (st_img->zoom), (width + st_img->x_ax) * st_img->zoom, -2.5, 1);
            st_img->y0 = ft_map(st_img->y, st_img->y_ax * (st_img->zoom), (height + st_img->y_ax) * st_img->zoom, -1.5, 1.5);
			st_img->cx = st_img->x0;
            st_img->cy = st_img->y0;
            st_img->color = color_iter_mand(st_img->color, st_img->x0, st_img->y0, st_img->cx, st_img->cy, val);
            mlx_pixel_image(st_img->x, st_img->y, st_img->addr, st_img->bpp, st_img->color);
        }
    }
}

int	loop_mand(t_img *st_img)
{
	if (st_img->draw)
	{
		draw_mand(1000, 1000, st_img->zoom, st_img);
		st_img->draw = 0;
		mlx_put_image_to_window(st_img->p_mlx, st_img->p_win,
			st_img->p_img, 0, 0);
	}
	return 1;
}

void    mandelbrot_set(t_img *st_img)
{
        st_img->x = 0.0;
        st_img->y = 0.0;
        st_img->x0 = 0.0;
        st_img->y0 = 0.0;
		st_img->x_ax = 0;
		st_img->y_ax = 0;
        st_img->color =0x80ff00;
    	st_img->p_win = mlx_new_window(st_img->p_mlx, WIN_SZ, WIN_SZ, "mand");
		st_img->draw = 1;
		draw_mand(1000, 1000, 0, st_img);
		mlx_hook(st_img->p_win, 2, 2, mandelbrot_drag, (void*)st_img);
		mlx_hook(st_img->p_win, 4, (1L << 4), mandelbrot_zoom, (void*)st_img);
		mlx_loop_hook(st_img->p_mlx, loop_mand, st_img);
}
