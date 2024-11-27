/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:08:44 by cwon              #+#    #+#             */
/*   Updated: 2024/11/27 20:30:01 by cwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

#include <math.h>

typedef struct s_complex
{
	double	real;
	double	imaginary;
}	t_complex;

t_complex	new_complex(double re, double im);
t_complex	add(t_complex x, t_complex y);
t_complex	multiply(t_complex x, t_complex y);
double		complex_abs(t_complex z);

#endif