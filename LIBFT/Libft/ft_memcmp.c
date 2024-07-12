/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 02:14:31 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/03/20 17:12:27 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	index;

	index = 0;
	while (n--)
	{
		if (((unsigned char *)s1)[index] != ((unsigned char *)s2)[index])
			return (((unsigned char *)s1)[index]
					- ((unsigned char *)s2)[index]);
		index++;
	}
	return (0);
}
/*
int main()
{
	char c;
	char block1[]= "aaaaaa";
	char block2[]= "aaaab";
	c = strncmp(block1, block2, 6) + '0';
	write(1, &c, 1);	
}
*/