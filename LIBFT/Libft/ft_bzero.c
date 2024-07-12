/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:45:45 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/04/05 21:23:31 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*p;

	p = str;
	while (n != 0)
	{
		p[n - 1] = 0;
		n--;
		
	}
}

/*
#include<stdio.h>
int main(void)
{
	char str[15] = "learning";
    printf("\"%s\"", str);
	ft_bzero(str, 3);
	printf("\"%s\"", str);
}
*/
