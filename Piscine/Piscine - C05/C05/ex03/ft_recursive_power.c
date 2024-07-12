/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:37:20 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/04/14 01:34:37 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int recursion(int a, int nb, int power)
{
	if (power > 0)
	{
		a *= nb;
		a = recursion(a, nb, (power-1));
	} 
	return (a);
}

int ft_recursive_power(int nb, int power)
{
	int a;
	a = recursion(1, nb, power);
	return(a);
}

/*
int main()
{
	int a;
	char character;
	a = ft_recursive_power(10,6);
	while(a!=0)
	{
		character = (a % 10) + '0';
		write(1, &character, 1);
		a /= 10;
	}

	return (0);
}
*/
