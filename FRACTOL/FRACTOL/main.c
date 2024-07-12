/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 05:41:01 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/06/04 05:42:38 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argn, char **argv)
{
	t_fractal	fractal;

	if ((2 == argn && (!ft_strncmp(argv[1], "mandelbrot", 10)
				|| !ft_strncmp(argv[1], "burning ship", 12))) || (argn == 4
			&& !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		if (argn == 4)
		{
			fractal.julia_x = atodbl(argv[2]);
			fractal.julia_y = atodbl(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		write(1, "Check Arguments", 16);
		exit(EXIT_FAILURE);
	}
}
