/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 05:59:49 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/06/04 08:29:51 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{	
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * (fractal->zoom));
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * (fractal->zoom));
	else if (keysym == XK_Up)
		fractal->shift_y += (0.5 * (fractal->zoom));
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.5 * (fractal->zoom));
	else if (keysym == XK_plus)
	{
		fractal->zoom *= 0.95;
		fractal->iterations_definition += 1;
	}
	else if (keysym == XK_minus)
	{
		fractal->zoom *= (1 / 0.95);
		fractal->iterations_definition -= 1;
	}
	else if (keysym == XK_x)
		change_colour(fractal);
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button4)
	{
		fractal->shift_x -= 3 * fractal->zoom
			* (0.5 - (x / (fractal->size * 1.4)));
		fractal->shift_y += 2 * fractal->zoom * (0.5 - (y / fractal->size));
		fractal->zoom *= 0.95;
	}
	else if (button == Button5)
	{
		fractal->shift_x += 3 * fractal->zoom
			* (0.5 - (x / (fractal->size * 1.4)));
		fractal->shift_y -= 2 * fractal->zoom * (0.5 - (y / (fractal->size)));
		fractal->zoom *= (1 / 0.95);
	}
	fractal_render(fractal);
	return (0);
}

void	change_colour(t_fractal *fractal)
{
	if (fractal->colour1 == 12708861)
	{
		fractal->colour2 = 16644425;
		fractal->colour3 = 16782001;
		fractal->colour1 = 6844736;
	}
	else if (fractal->colour1 == 6844736)
	{
		fractal->colour3 = 11594476;
		fractal->colour1 = 12551447;
		fractal->colour2 = 14744546;
	}
	else if (fractal->colour1 == 12551447)
	{
		fractal->colour3 = 0;
		fractal->colour1 = 12708861;
		fractal->colour2 = 0;
	}
}
