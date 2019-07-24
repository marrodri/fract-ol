

#include "fract.h"

int main(int argc, char **argv)
{
	void *p_mlx;
	void *p_win;
	void *p_img;
	t_img *st_img;
	
	st_img = malloc(sizeof(t_img));

	fract_init(st_img);

	return 0;
}