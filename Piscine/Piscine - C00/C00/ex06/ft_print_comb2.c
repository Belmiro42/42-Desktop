/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 05:10:11 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/04/14 20:49:49 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fn(int s, int b, char comb[5], char sp[2])
{
	comb[0] = s / 10 + '0';
	comb[1] = s % 10 + '0';
	comb[3] = b / 10 + '0';
	comb[4] = b % 10 + '0';
	write(1, &comb, 5);
	if (s != 98)
	{
		write(1, &sp, 2);
	}
}

void	ft_print_comb2(void)
{
	char	comb[5];
	char	sp[2];
	int		s;
	int		b;

	sp[0] = ',';
	sp[1] = ' ';
	s = 0;
	comb[2] = ' ';
	while (s != 100)
	{
		b = 0;
		while (b != 100)
		{
			{
				fn(s, b, &comb[5], &sp[2]);
			}
			b++;
		}
		s++;
	}
}
