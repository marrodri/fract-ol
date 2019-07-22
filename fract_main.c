

#include "fract.h"

int		mlx_pixel_image(int x, int y, char *addr, int bpp)
{
	if (x < 0 || y < 0 || x >= WIN_SZ || y >= WIN_SZ)
		return (0);
	*((int *)(addr + (x + y * WIN_SZ) * bpp)) = 0x80ff00;
	return (1);
}

int main(int argc, char **argv)
{
	void *p_mlx;
	void *p_win;
	void *p_img;
	t_img *st_img;
	
	st_img = malloc(sizeof(t_img));


	p_mlx = mlx_init();
	p_win = mlx_new_window(p_mlx, WIN_SZ, WIN_SZ, "test window");
	p_img = mlx_new_image(p_mlx, WIN_SZ, WIN_SZ);
	st_img->addr = mlx_get_data_addr(p_img, &st_img->bpp, 
		&st_img->sl, &st_img->endn);
	st_img->bpp /= 8;
	mlx_pixel_image(500,500, st_img->addr, st_img->bpp);
	mlx_put_image_to_window(p_mlx, p_win, p_img, 0, 0);

	mlx_loop(p_mlx);
	return 0;
}