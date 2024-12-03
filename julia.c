/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:01:51 by cwon              #+#    #+#             */
/*   Updated: 2024/12/03 22:20:07 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static inline void	color_pixel(t_fractol *f, int x, int y, int color)
{
	*((int *)(f->img_ptr + (y * f->ll + x * (f->bpp / 8)))) = color;
}

static inline void	julia(t_fractol *f)
{
	double	temp;
	int		i;

	f->zx = (f->x / f->scale) + f->offset_x;
	f->zy = (f->y / f->scale) + f->offset_y;
	f->cx = f->init_cx;
	f->cy = f->init_cy;
	i = -1;
	while (++i < ITERATION && f->zx * f->zx + f->zy * f->zy < __DBL_MAX__)
	{
		temp = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = 2 * f->zx * f->zy + f->cy;
		f->zx = temp;
	}
	if (i == ITERATION)
		color_pixel(f, f->x, f->y, 0x000000);
	else
		color_pixel(f, f->x, f->y, f->color * i);
}

void	plot_julia(t_fractol *f)
{
	f->x = -1;
	while (++(f->x) < SIZE)
	{
		f->y = -1;
		while (++(f->y) < SIZE)
			julia(f);
	}
}
