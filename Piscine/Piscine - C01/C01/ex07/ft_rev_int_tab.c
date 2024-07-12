/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:15:32 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/14 16:29:51 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	count;
	int	temp;

	count = size / 2;
	while (count > 0)
	{
		temp = tab[count - 1];
		tab[count - 1] = tab[size - count];
		tab[size - count] = temp;
		--count;
	}
}

/*
int main(void)
{
	int ls[]= {1, 2, 3, 4, 5};
	ft_rev_int_tab(&ls, 5);
	printf("%d", ls[0]);
	printf("%d", ls[1]);
	printf("%d", ls[2]);
	printf("%d", ls[3]);
	printf("%d", ls[4]);
	return(0);
}
 */
