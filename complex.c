/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:15:28 by cwon              #+#    #+#             */
/*   Updated: 2024/11/27 20:29:48 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

t_complex	new_complex(double re, double im)
{
	t_complex	result;

	result.real = re;
	result.imaginary = im;
	return (result);
}

t_complex	add(t_complex x, t_complex y)
{
	t_complex	result;

	result.real = x.real + y.real;
	result.imaginary = x.imaginary + y.imaginary;
	return (result);
}

t_complex	multiply(t_complex x, t_complex y)
{
	t_complex result;

	result.real = (x.real * y.real) - (x.imaginary * y.imaginary);
	result.imaginary = (x.real * y.imaginary) + (x.imaginary * y.real);
	return (result);
}

double	complex_abs(t_complex z)
{
	return (sqrt((z.real * z.real) + (z.imaginary * z.imaginary)));
}
