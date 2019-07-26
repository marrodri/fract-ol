
#include "fract.h"

//TODO implement properly the zoom function
// void    mandelbrot_algo(double width, double height, double val, t_img *st_img, t_manset *st_manset)
// {
//     double x = 0.0;
//     double y = 0.0;
//     double x0 = 0;
//     double y0 = 0;
//     int i = 0;
//     int max_i = 1000; //iterations
//     double cx;
//     double cy;
//     double x_sq = 0;
//     double y_sq = 0;
//     double color = 0x80ff00;
//     double old_zoom;
//     cx = 0;
//     cy = 0;
//     printf("new change\n");
//     for(x = 0; x < width; x++)
//     {
//         for(y = 0; y < height; y++)
//         {
//             x0 = ft_map(x, 0, width, -2.0, 1);
//             y0 = ft_map(y, 0, height, -1, 1);
//             i = 0;
//             cx = x0;
//             cy = y0;
//             while(i < max_i)
//             {
//                 x_sq = (x0 * x0) - (y0 * y0);
//                 y_sq = 2 * x0 * y0;

//                 x0 = x_sq + cx + val;
//                 y0 = y_sq + cy + val;
//                 if((x0 * x0) + (y0 * y0) > 16)
//                     break;
//                 i++;
//             }
//             color = ft_map(i, 0, max_i, 0, 1);
//             color = ft_map(sqrt(color),0,1,0,0x80ff00);
//             if(i == max_i)
//             {
//                 color = 0;
//             }
//             mlx_pixel_image(x, y, st_img->addr, st_img->bpp,color);

//         }
//     }
// }
int mandelbrot_zoom(int i, int x, int y, void *param)
{
	t_img *st_img;
	t_manset *st_manset;

	st_manset = malloc(sizeof(t_manset));
	st_img = (param);
	if (i == 5)
	{
		st_img->zoom = st_img->zoom + 5;
		draw_mand(1000, 1000, st_img->zoom, st_img, st_manset);
	}
	else if (i == 4)
	{
		st_img->zoom = st_img->zoom-5;
		draw_mand(1000, 1000, st_img->zoom ,st_img, st_manset);
	}
	mlx_put_image_to_window(st_img->p_mlx, st_img->p_win, st_img->p_img, 0, 0);
	return (0);
}

void			draw_mand(double width, double height, double val, t_img *st_img, t_manset *st_manset)
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
    double old_zoom;
    cx = 0;
    cy = 0;
    printf("new change\n");
    for(x = 0; x < width; x++)
    {
        for(y = 0; y < height; y++)
        {
            x0 = ft_map(x, 0, width, -2.0, 1);
            y0 = ft_map(y, 0, height, -1, 1);
            i = 0;
            cx = x0;
            cy = y0;
            while(i < max_i)
            {
                x_sq = (x0 * x0) - (y0 * y0);
                y_sq = 2 * x0 * y0;

                x0 = x_sq + cx + val;
                y0 = y_sq + cy + val;
                if((x0 * x0) + (y0 * y0) > 16)
                    break;
                i++;
            }
            color = ft_map(i, 0, max_i, 0, 1);
            color = ft_map(sqrt(color),0,1,0,0x80ff00);
            if(i == max_i)
            {
                color = 0;
            }
            mlx_pixel_image(x, y, st_img->addr, st_img->bpp,color);

        }
    }
}