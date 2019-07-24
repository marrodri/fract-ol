
//TODO make the mandelbrot algo to pixel

// mandelbrot algo guide from js to c


#include "fract.h"

int		mlx_pixel_image(int x, int y, char *addr, int bpp)
{
	if (x < 0 || y < 0 || x >= WIN_SZ || y >= WIN_SZ)
		return (0);
	*((int *)(addr + (x + y * WIN_SZ) * bpp)) = 0x80ff00;
	return (1);
}
double ft_map(double value, double cur_start, double cur_end, double new_start, double new_end)
{
    return ((value - cur_start) / (cur_end-cur_start)) * (new_end-new_start) + new_start;
}

void    mandelbrot_algo(double width, double height, t_img *st_img)
{
    // double x = 0.0;
    // double y = 0.0;
    // double x0 = -2.5;
    // double x1 = 1;
    // double y0 = -1;
    // double y1 = 1;
    // int i = 0;
    // int max_i = 1000; //iterations

    // for(x = 0; x < width; x++)
    // {
    //     for(y = 0; y < height; y++)
    //     {
    //         double a = ft_map(x, 0, width, -2, 2);
    //         double b = ft_map(y, 0, height, -2, 2);

    //         double ca = a;
    //         double cb = b;

    //         double n = 0;
    //         double z = 0;
    //         while(n < 100)
    //         {

    //         }
    //     }
    // }
    mlx_pixel_image(100,500, st_img->addr, st_img->bpp);
    mlx_pixel_image(110,500, st_img->addr, st_img->bpp);
    mlx_pixel_image(120,500, st_img->addr, st_img->bpp);
    mlx_pixel_image(130,500, st_img->addr, st_img->bpp);
    mlx_pixel_image(140,500, st_img->addr, st_img->bpp);
    mlx_pixel_image(150,500, st_img->addr, st_img->bpp);
    mlx_pixel_image(160,500, st_img->addr, st_img->bpp);

}


void draw_mand(double width, double height, t_img *st_img)
{
    mandelbrot_algo(width, height, st_img);
}