/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:45:40 by cwon              #+#    #+#             */
/*   Updated: 2025/01/12 13:53:52 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

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
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364

# define SPACE 32

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

// fractol_bonus.c
void	fractol(int argc, char **argv);
int		flush_fractol(t_fractol *f);
int		plot(t_fractol *f);

// hook_bonus.c
int		scroll_hook(int code, int x, int y, t_fractol *f);
int		key_hook(int code, t_fractol *f);

// mandelbrot_bonus.c
void	plot_mandelbrot(t_fractol *f);

// julia_bonus.c
void	plot_julia(t_fractol *f);

// burning_ship_bonus.c
void	plot_burning_ship(t_fractol *f);

#endif