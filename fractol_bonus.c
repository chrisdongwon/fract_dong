/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:50:50 by cwon              #+#    #+#             */
/*   Updated: 2025/01/12 12:58:11 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	flush_fractol(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->window);
	free(f->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	init_values(t_fractol *f, char **argv)
{
	if (!ft_strncmp(f->name, "julia", 6))
	{
		f->init_cx = ft_atof(argv[2]);
		f->init_cy = ft_atof(argv[3]);
	}
}

static void	init_fractol(t_fractol *f, int argc, char **argv)
{
	f->mlx = mlx_init();
	f->window = mlx_new_window(f->mlx, SIZE, SIZE, "Fract'ol");
	f->img = mlx_new_image(f->mlx, SIZE, SIZE);
	f->img_ptr = mlx_get_data_addr(f->img, &f->bpp, &f->ll, &f->endian);
	if (argc == 2 && (!ft_strncmp(argv[1], "mandelbrot", 11)))
		f->name = argv[1];
	else if (argc == 4 && (!ft_strncmp(argv[1], "julia", 6)))
		f->name = argv[1];
	else if (argc == 2 && (!ft_strncmp(argv[1], "burning_ship", 13)))
		f->name = argv[1];
	f->color = 0xFCBE11;
	f->x = 0;
	f->y = 0;
	f->scale = SCALE;
	f->offset_x = (-SIZE / 2) / f->scale;
	f->offset_y = f->offset_x;
	init_values(f, argv);
	mlx_mouse_hook(f->window, scroll_hook, f);
	mlx_key_hook(f->window, key_hook, f);
	mlx_hook(f->window, 17, 0L, flush_fractol, f);
}

int	plot(t_fractol *f)
{
	if (!ft_strncmp(f->name, "mandelbrot", 11))
		plot_mandelbrot(f);
	if (!ft_strncmp(f->name, "julia", 6))
		plot_julia(f);
	if (!ft_strncmp(f->name, "burning_ship", 13))
		plot_burning_ship(f);
	mlx_put_image_to_window(f->mlx, f->window, f->img, 0, 0);
	return (0);
}

void	fractol(int argc, char **argv)
{
	t_fractol	f;

	init_fractol(&f, argc, argv);
	plot(&f);
	mlx_loop(f.mlx);
}
