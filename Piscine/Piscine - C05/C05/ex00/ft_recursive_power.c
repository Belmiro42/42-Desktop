/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:15:18 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/23 21:28:11 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int fact(int nb, int a)
{
	if (nb>0)
	{
        a *= nb;
        a = fact((nb-1), a);
    }
    return(a);
}

int ft_recursive_factorial(int nb)
{
    int a;
    a=1;
    a = fact(nb, a);
    return(a);
}

/*
int main()
{
	int a;
	char character;
	a = ft_recursive_factorial(5);
	while(a!=0)
	{
		character = (a % 10) + '0';
		write(1, &character, 1);
		a /= 10;
	}

	return (0);
}
*/

