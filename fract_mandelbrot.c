
//TODO make the mandelbrot algo to pixel

// mandelbrot algo guide from js to c


#include "fract.h"

int		mlx_pixel_image(int x, int y, char *addr, int bpp, int color)
{
	if (x < 0 || y < 0 || x >= WIN_SZ || y >= WIN_SZ)
		return (0);
	*((int *)(addr + (x + y * WIN_SZ) * bpp)) = color;
	return (1);
}
double ft_map(double value, double cur_start, double cur_end, double new_start, double new_end)
{
    return ((value - cur_start) / (cur_end-cur_start)) * (new_end-new_start) + new_start;
}


//TODO FINISH THIS ALGORITHM
void    mandelbrot_algo(double width, double height, t_img *st_img)
{
    double x = 0.0;
    double y = 0.0;
    double x0 = 0;
    double y0 = 0;
    int i = 0;
    int max_i = 1000; //iterations
    double cx;
    double cy;
    double x_sq = 0;
    double y_sq = 0;
    double color = 0x80ff00;
    cx = 0;
    cy = 0;
    for(x = 0; x < width; x++)
    {
        for(y = 0; y < height; y++)
        {
            x0 = ft_map(x, 0, width, -2.5, 1);
            y0 = ft_map(y, 0, height, -1, 1);
            i = 0;
            cx = x0;
            cy = y0;
            while(i < max_i)
            {
                x_sq = (x0 * x0) - (y0 * y0);
                y_sq = 2 * x0 * y0;

                x0 = x_sq + cx;
                y0 = y_sq + cy;
                if((x0*x0) +(y0*y0) > 16)
                {
                    break;
                }
                i++;
            }
            color = ft_map(i, 0, max_i, 0, 1);
            color = ft_map(sqrt(color),0,1,0,0x80ff00);
            if(i == max_i)
            {
                double color = 0;
            }
            mlx_pixel_image(x0,y0, st_img->addr, st_img->bpp,color);
        }
    }

}


void draw_mand(double width, double height, t_img *st_img)
{
    mandelbrot_algo(width, height, st_img);
}