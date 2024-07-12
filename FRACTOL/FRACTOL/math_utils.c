/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 05:43:58 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/06/04 05:45:54 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min,
		double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num) / (old_max) + new_min);
}

t_complex	sum_complex(t_complex z, t_complex c)
{
	t_complex	result;

	result.x = z.x + c.x;
	result.y = z.y + c.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * (z.x * z.y);
	return (result);
}

t_complex	absolute_square(t_complex z)
{
	t_complex	result;

	if (z.x < 0)
		z.x *= -1;
	if (z.y < 0)
		z.y *= -1;
	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = -(2 * (z.x * z.y));
	return (result);
}
