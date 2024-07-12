/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:45:02 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/04/13 23:33:15 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long int	n;
	char		chara;

	n = (long int)nb;
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	if ((n / 10) > 0)
		ft_putnbr(n / 10);
	chara = (n % 10) + '0';
	write(1, &chara, 1);
}

/*
int main(void)
{
	int ints	= -20351589;
	ft_putnbr(ints);
}
*/
