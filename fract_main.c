/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:45:45 by marrodri          #+#    #+#             */
/*   Updated: 2019/07/25 18:45:52 by marrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	fract_checker()
{
	//TODO set an input checker if the fractal exists, if not return 0;
	return (0);
}

int	main(int argc, char **argv)
{
	void	*p_mlx;
	void	*p_win;
	void	*p_img;
	t_img	*st_img;

	if (argc >= 2)
	{
		st_img = malloc(sizeof(t_img));
		fract_init(st_img, argv[1]);
	}
	else
	{
		ft_putstr("./fract <mandelbrot, julia> \n");
	}
	return (0);
}
