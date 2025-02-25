/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:45:40 by cwon              #+#    #+#             */
/*   Updated: 2025/01/12 13:48:55 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include "libft/libft.h"

# define SIZE 500
# define ITERATION 75
# define SCALE 200
# define ZOOM_FACTOR 1.05

# define SCROLL_UP 4
# define SCROLL_DOWN 5

# define ESC 65307

// bpp: bits per pixel
// ll: line length
typedef struct s_fractol
{
	void	*mlx;
	void	*window;

	void	*img;
	void	*img_ptr;
	int		bpp;
	int		ll;
	int		endian;

	char	*name;
	int		color;

	int		x;
	int		y;

	double	scale;
	double	offset_x;
	double	offset_y;

	double	zx;
	double	zy;

	double	init_cx;
	double	init_cy;
	double	cx;
	double	cy;
}	t_fractol;

// fractol.c
void	fractol(int argc, char **argv);
int		flush_fractol(t_fractol *f);
int		plot(t_fractol *f);

// hook.c
int		scroll_hook(int code, int x, int y, t_fractol *f);
int		key_hook(int code, t_fractol *f);

// mandelbrot.c
void	plot_mandelbrot(t_fractol *f);

// julia.c
void	plot_julia(t_fractol *f);

#endif