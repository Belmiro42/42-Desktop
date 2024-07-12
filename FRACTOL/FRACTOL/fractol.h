/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 05:57:14 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/06/05 14:18:23 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h> 
# include <X11/X.h> 
# include <X11/keysym.h> 
# include "MLX-LNX/mlx.h"

typedef struct s_complex
{
	double	x;
	double	y;
}		t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	double	size;
	int		colour1;
	int		colour2;
	int		colour3;
}		t_fractal;

int			ft_strncmp(char *s1, char *s2, int n);
void		ft_putstr_fd(char *s, int fd);
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
double		map(double unscaled_num, double new_min,
				double new_max, double old_max);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	absolute_square(t_complex z);
t_complex	fractalise(t_complex z, t_complex c, t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			track(int x, int y, t_fractal *fractal);
double		atodbl(char *s);
void		change_colour(t_fractal *fractal);
void		atodbl2(char *s, double *fractional_part);

#endif
