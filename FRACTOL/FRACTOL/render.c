/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 05:33:50 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/06/04 05:40:05 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int colour)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = colour;
}

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			iterator;
	int			colour;

	iterator = 0;
	z.x = (map(x, -3, 3, ((fractal->size * 1.4) - 1)) * fractal->zoom)
		+ fractal->shift_x;
	z.y = (map(y, 2, -2, (fractal->size - 1)) * fractal->zoom)
		+ fractal->shift_y;
	mandel_vs_julia(&z, &c, fractal);
	while (iterator < fractal->iterations_definition)
	{
		z = fractalise(z, c, fractal);
		if (((z.x * z.x) + (z.y * z.y)) > fractal->escape_value)
		{
			colour = map(iterator, fractal->colour2, fractal->colour3,
					fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, colour);
			return ;
		}
		iterator++;
	}
	my_pixel_put(x, y, &fractal->img, fractal->colour1);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < fractal->size)
	{
		x = -1;
		while (++x < fractal->size * 1.4)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}

t_complex	fractalise(t_complex z, t_complex c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "burning ship", 13))
		return (sum_complex(absolute_square(z), c));
	else
		return (sum_complex(square_complex(z), c));
}
