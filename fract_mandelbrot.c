
//TODO make the mandelbrot algo to pixel

// mandelbrot algo guide from js to c


#include <fract.h>

int		mlx_pixel_image(int x, int y, char *addr, int bpp)
{
	if (x < 0 || y < 0 || x >= WIN_SZ || y >= WIN_SZ)
		return (0);
	*((int *)(addr + (x + y * WIN_SZ) * bpp)) = 0x80ff00;
	return (1);
}

void mandelbrot_algo()
{
    
}


void draw_mand()
{


}