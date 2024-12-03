/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 09:08:43 by cwon              #+#    #+#             */
/*   Updated: 2024/12/03 22:30:35 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static inline void	rescale(t_fractol *f, int x, int y, double factor)
{
	f->offset_x += (x - x / factor) / f->scale;
	f->offset_y += (y - y / factor) / f->scale;
	f->scale *= factor;
}

int	scroll_hook(int code, int x, int y, t_fractol *f)
{
	if (code == SCROLL_UP)
		rescale(f, x, y, ZOOM_FACTOR);
	else if (code == SCROLL_DOWN)
		rescale(f, x, y, 1 / ZOOM_FACTOR);
	plot(f);
	return (0);
}

int	key_hook(int code, t_fractol *f)
{
	if (code == ESC)
		flush_fractol(f);
	else if (code == LEFT)
		f->offset_x -= (SIZE / 10) / f->scale;
	else if (code == RIGHT)
		f->offset_x += (SIZE / 10) / f->scale;
	else if (code == UP)
		f->offset_y -= (SIZE / 10) / f->scale;
	else if (code == DOWN)
		f->offset_y += (SIZE / 10) / f->scale;
	else if (code == SPACE)
		f->color += (255 * 255 * 255) / 100;
	plot(f);
	return (0);
}
