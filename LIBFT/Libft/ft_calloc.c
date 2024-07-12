/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:41:20 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/03/28 20:02:54 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
		return (malloc(0));
	ptr = malloc (count * size);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}

/*
int main() {
    int num_elements = 5;
    int element_size = sizeof(int);

    int* my_array = (int*)ft_calloc(num_elements, element_size);
    free(my_array);
    return 0;
}
*/