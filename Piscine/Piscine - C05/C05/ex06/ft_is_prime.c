/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:10:06 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/23 22:25:33 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_is_prime(int nb)
{
	int count;
	
	count = 2;
	if (nb == 2)
	{
		return(1);
	}
	while (count<nb)
	{
		if ((nb%count) == 0)
		{
			return (0);
		}
		count ++;
	}
	return (1);
}

/*
int main(void)
{
	int a;
	char character;

	a = ft_is_prime(4444);
	while(a!=0)
	{
		character = (a % 10) + '0';
		write(1, &character, 1);
		a /= 10;
	}
	return(0);
}
*/
