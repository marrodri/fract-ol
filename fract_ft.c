
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
