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

int	fract_checker(char *input)
{
	if (!ft_strcmp(input, "mandelbrot") || !ft_strcmp(input, "julia")
			|| !ft_strcmp(input, "tricorn"))
	{
		return (1);
	}
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_thrd_arg	*st_thrd_arg;

	if (argc >= 2 && fract_checker(argv[1]))
	{
		st_thrd_arg = malloc(sizeof(t_thrd_arg));
		st_thrd_arg->st_img = malloc(sizeof(t_img));
		st_thrd_arg->st_map = malloc(sizeof(t_map));
		st_thrd_arg->fract = malloc(sizeof(t_fract));
		fract_init(st_thrd_arg, argv[1]);
	}
	else
	{
		ft_putstr("./fract <mandelbrot, julia, tricorn> \n");
	}
	return (0);
}
