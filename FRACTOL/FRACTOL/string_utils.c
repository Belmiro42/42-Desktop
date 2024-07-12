/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 05:31:33 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/06/05 14:27:25 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
		--n;
	}
	return (*s1 - *s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		ft_putstr_fd(s + 1, fd);
	}
}

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s != '.' && *s && *s >= 48 && *s <= 57)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if (*s == '.')
		++s;
	atodbl2(s, &fractional_part);
	return ((integer_part + fractional_part) * sign);
}

void	atodbl2(char *s, double *fractional_part)
{
	double	pow;

	pow = 1;
	while (*s >= 48 && *s <= 57)
	{
		pow /= 10;
		*fractional_part = *fractional_part + (*s++ - 48) * pow;
	}
	if (*s != '\0')
	{
		write(1, "Numbers Not Good", 16);
		exit(EXIT_FAILURE);
	}
}
