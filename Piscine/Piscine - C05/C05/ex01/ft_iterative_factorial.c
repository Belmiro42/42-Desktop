/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:06:33 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/23 21:14:06 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_iterative_factorial(int nb)
{
    int a;

    a=1;
    while(nb>=1)
    {
        a *= nb;
		nb-=1;
    }
    return(a);
}

/*
int main()
{
	int a;
	char character;
	a = ft_iterative_factorial(5);
	while(a!=0)
	{
		character = (a % 10) + '0';
		write(1, &character, 1);
		a /= 10;
	}
	
	return (0);
}
*/
