
#include "fract.h"

int		close_win_x(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int		esc_key(int key, void *param)
{
	(void)param;
	if (key == 53)
		exit(1);
	return (0);
}

int mouse_move(int x, int y, void *param)
{
	printf("x|%d|, y|%d|\n",x,y);
	return 0;
}

int mandelbrot_zoom(int i, int x, int y, void *param)
{
	t_img *st_img;
	t_manset *st_manset;

	st_manset = malloc(sizeof(t_manset));
	st_img = (param);
	
	// printf("i is |%d|, x is|%d|, y is|%d|\n", i, x, y);
	if(i == 4)
	{
		st_img->zoom = st_img->zoom + 5;
		printf("zoom in 4 is |%f|\n", st_img->zoom);
		// (((t_manset*)&param))->zoom = st_img->zoom;
	mlx_put_image_to_window(st_img->p_mlx, st_img->p_win, st_img->p_img, 0, 0);
		draw_mand(1000, 1000, st_img->zoom ,st_img, st_manset);
	}
	else if(i == 5)
	{
		st_img->zoom = st_img->zoom-5;

		draw_mand(1000, 1000, st_img->zoom ,st_img, st_manset);
		mlx_put_image_to_window(st_img->p_mlx, st_img->p_win, st_img->p_img, 0, 0);
		printf("zoom out 5 is |%f|\n", st_img->zoom);
	}
	// if(st_img->zoom > 0)
	// {
	// 	draw_mand(1000, 1000, st_img, st_manset);
	// }
	// else if(st_img->zoom < 0)
	// {
	// 	mlx_pixel_image(500, 500 - st_img->zoom, st_img->addr, st_img->bpp, 0x80ff00);
	// }
	// mlx_put_image_to_window(st_img->p_mlx, st_img->p_win, st_img->p_img, 0, 0);
	return 0;
}

void fract_init(t_img *st_img, char *fract)
{
	t_manset *st_manset;
	t_julset *st_julset;

	st_manset = malloc(sizeof(t_manset));
	st_julset = malloc(sizeof(t_julset));
	st_img->zoom = 0;
	st_img->p_mlx = mlx_init();
	st_img->p_win = mlx_new_window(st_img->p_mlx, WIN_SZ, WIN_SZ, "test window");
	st_img->p_img = mlx_new_image(st_img->p_mlx, WIN_SZ, WIN_SZ);
	st_img->addr = mlx_get_data_addr(st_img->p_img, &st_img->bpp, 
		&st_img->sl, &st_img->endn);
	st_img->bpp /= 8;
	if(!ft_strcmp(fract ,"mandelbrot"))
	{

	draw_mand(1000,1000, 0,st_img, st_manset);
	mlx_hook(st_img->p_win, 4, (1L << 4) , mandelbrot_zoom, (void*)st_img);
	mlx_put_image_to_window(st_img->p_mlx, st_img->p_win, st_img->p_img, 0, 0);
	}
	else
	{
		mlx_pixel_image(10, 10, st_img->addr, st_img->bpp, 0x80ff00);
		mlx_pixel_image(20, 20, st_img->addr, st_img->bpp, 0x80ff00);
		mlx_pixel_image(30, 30, st_img->addr, st_img->bpp, 0x80ff00);
		mlx_pixel_image(40, 40, st_img->addr, st_img->bpp, 0x80ff00);
		mlx_pixel_image(50, 50, st_img->addr, st_img->bpp, 0x80ff00);
		mlx_put_image_to_window(st_img->p_mlx, st_img->p_win, st_img->p_img, 0, 0);
	}
	mlx_key_hook(st_img->p_win, esc_key, (void *)0);
	mlx_hook(st_img->p_win, 17, (1L << 17), close_win_x, (void*)0);
	// mlx_hook(st_img->p_win, 6, (1L << 6), mouse_move, (void*)0);
	mlx_loop(st_img->p_mlx);
	
}