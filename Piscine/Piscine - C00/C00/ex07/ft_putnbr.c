/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 05:35:31 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/20 17:33:43 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int		u;
	int		remainder;
	char	neg;
	int		reverse;

	neg = '-';
	remainder = 0;
	reverse = 0;
	if (nb < 0)
	{
		nb = -nb;
		write(1, &neg, 1);
	}
	while (nb != 0)
	{
		remainder = nb % 10;
		reverse = reverse * 10 + remainder;
		nb /= 10;
	}
	while (reverse != 0)
	{
		u = reverse % 10 + '0';
		reverse = reverse / 10;
		write(1, &u, 1);
	}
}

/*
int main(void)
{
	ft_putnbr(-19235124);
	return(0);
}
*/
