/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:20:51 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/21 06:34:24 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	big_value;
	int	big_index;
	int	index;

	while (size > 0)
	{
		index = 0;
		big_value = tab[0];
		big_index = 0;
		while (index != size)
		{
			if (tab[index] > big_value)
			{
				big_value = tab[index];
				big_index = index;
			}
			++index;
		}
		tab[big_index] = tab[size - 1];
		tab[size - 1] = big_value;
		--size;
	}
}

/*
int main(void)
{
    int arr[] = {1, 3, 4, 8, 2, 3, 1};
    ft_sort_int_tab(arr, 7);

    printf("Sorted array elements: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
*/
