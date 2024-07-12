/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laurvare <laurvare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:34:58 by laurvare          #+#    #+#             */
/*   Updated: 2024/02/11 13:43:51 by laurvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_h(int x, char left, char middle, char right)
{
	if (x >= 1)
		x--;
	{
		ft_putchar(left);
		while (x-- >= 2)
		{
			ft_putchar(middle);
		}
		if (x == 0)
			ft_putchar(right);
		ft_putchar('\n');
	}
}

void	print_v(int x, int y, char w)
{
	int	i;

	while (y-- > 2)
	{
		ft_putchar(w);
		i = 2;
		while (x > i++)
			ft_putchar(' ');
		if (x > 1)
		{
			ft_putchar(w);
		}
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		if (y >= 1)
			print_h(x, 'o', '-', 'o');
		print_v(x, y, '|');
		if (y >= 2)
			print_h(x, 'o', '-', 'o');
	}
	else
	{
		write(1, "ERROR\n", 6);
	}
}
