/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:13:44 by cwon              #+#    #+#             */
/*   Updated: 2024/12/05 14:10:55 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static inline void	color_pixel(t_fractol *f, int x, int y, int color)
{
	*((int *)(f->img_ptr + (y * f->ll + x * (f->bpp / 8)))) = color;
}

static inline void	burning_ship(t_fractol *f)
{
	double	temp;
	int		i;

	f->zx = 0;
	f->zy = 0;
	f->cx = (f->x / f->scale) + f->offset_x;
	f->cy = (f->y / f->scale) + f->offset_y;
	i = -1;
	while (++i < ITERATION && f->zx * f->zx + f->zy * f->zy <= 4)
	{
		temp = f->zx * f->zx - f->zy * f->zy + f->cx;
		f->zy = fabs(2 * f->zx * f->zy) + f->cy;
		f->zx = temp;
	}
	if (i == ITERATION)
		color_pixel(f, f->x, f->y, 0x000000);
	else
		color_pixel(f, f->x, f->y, f->color * i);
}

void	plot_burning_ship(t_fractol *f)
{
	f->x = -1;
	while (++(f->x) < SIZE)
	{
		f->y = -1;
		while (++(f->y) < SIZE)
			burning_ship(f);
	}
}