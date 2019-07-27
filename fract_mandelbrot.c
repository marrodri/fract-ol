/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 22:16:31 by marrodri          #+#    #+#             */
/*   Updated: 2019/07/25 22:16:32 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

//TODO implement properly the zoom function
int     mandelbrot_zoom(int i, int x, int y, void *param)
{
	t_img       *st_img;
	t_manset    *st_manset;

	st_manset = malloc(sizeof(t_manset));
	st_img = (param);
	if (i == 5)
	{
		st_img->zoom = st_img->zoom + 1;
		draw_mand(1000, 1000, st_img->zoom, st_img, st_manset);
	}
	else if (i == 4)
	{
		st_img->zoom = st_img->zoom - 1;
		draw_mand(1000, 1000, st_img->zoom ,st_img, st_manset);
	}
	mlx_put_image_to_window(st_img->p_mlx, st_img->p_win, st_img->p_img, 0, 0);
	return (0);
}

// double  color_iteration(double color, double x, double y, double x0, double y0)
double  color_iteration(double color, double x0, double y0, double cx, double cy, double val)
{
    double x_sq;
    double y_sq;
    int i = 0;
    int max_i = 1000;
    double xtemp = 0;
    double ytemp = 0;
    while((i < max_i))
    {
        x_sq = (x0 * x0) - (y0 * y0);
        y_sq = 2 * x0 * y0;
        x0 = x_sq + cx;
        y0 = y_sq + cy;
        if((x0 * x0) + (y0 * y0) > 16)
            break;
        i++;
    }
    color = ft_map(i, 0, max_i, 0, 1, val);
    color = ft_map(sqrt(color),0,1,0,0x80ff00, val);
    if(i == max_i)
    {
        color = 0;
    }
    return color;
}

void    draw_mand(double width, double height, double val, t_img *st_img, t_manset *st_manset)
{
    int     i;
    int     max_i; //iterations

    printf("new change\n");
    for(st_manset->x = val; st_manset->x < width; st_manset->x++)
    {
        for(st_manset->y = val; st_manset->y < height; st_manset->y++)
        {
            st_manset->x0 = ft_map(st_manset->x, 0, width, -2.5, 1, st_manset->zoom);
            st_manset->y0 = ft_map(st_manset->y, 0, height, -1.5, 1.5, st_manset->zoom);
   
            st_manset->cx = st_manset->x0;
            st_manset->cy = st_manset->y0;
            st_manset->color = color_iteration(st_manset->color, st_manset->x0, st_manset->y0, st_manset->cx, st_manset->cy, val);
            // st_manset->color = color_iteration(st_manset->color, st_manset->x, st_manset->y, st_manset->x0, st_manset->y0);
            mlx_pixel_image(st_manset->x, st_manset->y, st_img->addr, st_img->bpp, st_manset->color);
        }
    }
}

void    mandelbrot_set(t_img *st_img, t_manset *st_manset)
{
        st_manset->x = 0.0;
        st_manset->y = 0.0;
        st_manset->x0 = 0.0;
        st_manset->y0 = 0.0;
        st_manset->cx = 0.0;
        st_manset->cy = 0.0;
        st_manset->color =0x80ff00;
    	st_img->p_win = mlx_new_window(st_img->p_mlx, WIN_SZ, WIN_SZ, "mand");
		draw_mand(1000, 1000, 0, st_img, st_manset);
		mlx_hook(st_img->p_win, 4, (1L << 4), mandelbrot_zoom, (void*)st_img);
		mlx_put_image_to_window(st_img->p_mlx, st_img->p_win,
				st_img->p_img, 0, 0);
}
