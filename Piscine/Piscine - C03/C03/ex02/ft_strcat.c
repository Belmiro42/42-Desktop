/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:51:25 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/04/13 00:01:09 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*copydest;
	char	*copysrc;

	copysrc = src;
	copydest = dest;
	while (*copydest)
	{
		copydest++;
	}
	while (*copysrc)
	{
		*copydest = *copysrc;
		copysrc++;
		copydest++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int main() 
{
    char str1[20] = "Hello, ";
    char *str2 = "world!";

    ft_strcat(str1, str2);

    printf("Concatenated string: %s\n", str1);

    return 0;
}
*/
