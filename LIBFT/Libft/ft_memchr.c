/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 02:12:43 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/03/16 19:22:25 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		if (*((unsigned char *)str + index) == (unsigned char)c)
			return ((void *)((char *)str + index));
		index++;
	}
	return (0);
}

/*
int main()
{
	char str[] = "asasd";
	char *s;
	char p;
	s = ft_memchr(str, 'd', 1000);
	p = *s;
	write(1, &p, 1);
}
*/