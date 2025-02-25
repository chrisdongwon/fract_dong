/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:40:25 by cwon              #+#    #+#             */
/*   Updated: 2025/01/14 14:08:13 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_valid_argument(int argc, char **argv)
{
	int	mandelbrot;
	int	julia;

	mandelbrot = (argc == 2) && (!ft_strncmp(argv[1], "mandelbrot", 11));
	julia = (argc == 4) && (!ft_strncmp(argv[1], "julia", 6)) && \
		ft_isfloat(argv[2]) && ft_isfloat(argv[3]);
	return (mandelbrot || julia);
}

int	main(int argc, char **argv)
{
	if (is_valid_argument(argc, argv))
		fractol(argc, argv);
	else
	{
		ft_printf("usage:\n");
		ft_printf("./fractol mandelbrot\n");
		ft_printf("./fractol julia [Re(c)] [Im(c)]\n");
	}
	return (0);
}
