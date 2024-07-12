/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:54:36 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/03/20 16:10:28 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	d = dest;
	s = src;
	while (n != 0)
	{
		n--;
		d[n] = s[n];
	}
	return (dest);
}

/*
#include<stdio.h>
int	main(void)
{
	char str[15] = "learning";
	char dest[15] = "";
	printf("\"%s\"", dest);
	ft_memcpy(dest, str, 3);
	printf("\"%s\"", dest);
}
*/