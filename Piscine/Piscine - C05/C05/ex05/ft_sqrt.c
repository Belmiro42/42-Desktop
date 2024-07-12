/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 22:39:06 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/23 22:50:14 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_sqrt(nb)
{
	int count;
	
	count = 2;
	while(nb > count)
	{
		if ((nb / count) == count)
		{
			return(count);
		}
		count++;
	}
	return (0);
}

/*
int main(void)
{
	int a;
	char character;

	a = ft_sqrt(16);
	while(a!=0)
	{
		character = (a % 10) + '0';
		write(1, &character, 1);
		a /= 10;
	}
	return(0);
}
*/
