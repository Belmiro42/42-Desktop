/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:03:44 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/03/16 17:31:27 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int ch, size_t n)
{
	unsigned char	*p;

	p = str;
	while (n != 0)
	{
		p[n - 1] = (unsigned char)ch;
		n--;
	}
	return (str);
}

/*
#include<stdio.h>
int main(void)
{
	char str[15] = "learning";
    printf("\"%s\"", str);
	ft_memset(str, '3', 3);
	printf("\"%s\"", str);
}
*/
