
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

int mouse_press(int i, int x, int y, void *param)
{
	t_manset *st_manset;

	st_manset = (param);
	// printf("i is |%d|, x is|%d|, y is|%d|\n", i, x, y);
	if(i == 4)
	{
		st_manset->zoom++;
		printf("zoom in 4 is |%f|\n", st_manset->zoom);
		(((t_manset*)&param))->zoom = st_manset->zoom;
	}
	else if(i == 5)
	{
		st_manset->zoom--;
		printf("zoom out 5 is |%f|\n", st_manset->zoom);
	}
	return 0;
}

int change_img(void *param)
{
	printf("img changed");
	return 0;
}

void fract_init(t_img *st_img)
{
	// todo initialize mlx and init here
	void *p_mlx;
	void *p_win;
	void *p_img;
	t_manset *st_manset;
	t_julset *st_julset;

	st_manset = malloc(sizeof(t_manset));
	st_julset = malloc(sizeof(t_julset));
	st_manset->zoom = 0;
	p_mlx = mlx_init();
	p_win = mlx_new_window(p_mlx, WIN_SZ, WIN_SZ, "test window");
	p_img = mlx_new_image(p_mlx, WIN_SZ, WIN_SZ);
	st_img->addr = mlx_get_data_addr(p_img, &st_img->bpp, 
		&st_img->sl, &st_img->endn);
	st_img->bpp /= 8;
	mlx_key_hook(p_win, esc_key, (void *)0);
	mlx_hook(p_win, 17, (1L << 17), close_win_x, (void*)0);
	mlx_hook(p_win, 6, (1L << 6), mouse_move, (void*)0);
	mlx_hook(p_win, 4, (1L << 4) , mouse_press, (void*)st_manset);
	draw_mand(1000,1000, st_img, st_manset);
	mlx_put_image_to_window(p_mlx, p_win, p_img, 0, 0);
	mlx_loop(p_mlx);
	
}