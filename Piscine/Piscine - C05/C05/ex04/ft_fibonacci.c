/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:57:40 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/23 22:07:50 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int recursive(int index1, int index2, int index)
{
	if (index>2)
	{
	index2 = recursive(index2, (index1 + index2), index-1);	
	}
	return(index2);
}


int ft_fibonacci(int index)
{
	int number;
	if(index< 0)
	{
		return (0);
	}
	if(index <2)
	{
		return (index);
	}
	number = recursive(1, 1, index);
	return (number);
}

/*
int main()
{
	int a;
	char character;
	a = ft_fibonacci(10);
	while(a!=0)
	{
		character = (a % 10) + '0';
		write(1, &character, 1);
		a /= 10;
	}

	return (0);
}
*/
