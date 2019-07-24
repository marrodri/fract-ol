
#include "fract.h"

void fract_init(t_img *st_img)
{
	// todo initialize mlx and init here
	void *p_mlx;
	void *p_win;
	void *p_img;

	p_mlx = mlx_init();
	p_win = mlx_new_window(p_mlx, WIN_SZ, WIN_SZ, "test window");
	p_img = mlx_new_image(p_mlx, WIN_SZ, WIN_SZ);
	st_img->addr = mlx_get_data_addr(p_img, &st_img->bpp, 
		&st_img->sl, &st_img->endn);
	st_img->bpp /= 8;

	//TODO function to draw image of fract;
	draw_mand(1000,1000, st_img);
	mlx_put_image_to_window(p_mlx, p_win, p_img, 0, 0);

	mlx_loop(p_mlx);
}