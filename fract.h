
#ifndef FRACT_H
# define FRACT_H
# define WIN_SZ 1000

# define MS_SCROLL_UP 4
# define MS_SCROLL_DW 5
# define MS_SCROLL_LF 6
# define MS_SCROLL_RT 7
# include <math.h>
# include <fcntl.h>
# include "includes/libft/libft.h"
# include "mlx.h"

#include <stdio.h>

typedef struct	s_map 
{
	int			x;
	int			y;
}				t_map;

typedef	struct	s_img
{
	char		*addr;
	int			bpp;
	int			endn;
	int			sl;
}				t_img;

typedef struct	s_app
{
    int			x_sz;
	int			y_sz;
} 
t_app;

typedef struct s_color
{
	int color_1;
	int color_2;
	int color_3;
	int color_4;
}				t_color;

typedef struct  s_mandelSet
{
	
}				t_mandelSet;

void fract_init(t_img *st_img);
int		mlx_pixel_image(int x, int y, char *addr, int bpp, int color);
void draw_mand(double width, double height, t_img *st_img);

#endif