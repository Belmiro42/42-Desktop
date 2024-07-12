/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:26:33 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/03/30 19:21:10 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst,
		const char *src, size_t buff_size)
{
	int	index;

	index = 0;
	while (buff_size > 1 && src[index])
	{
		dst[index] = src[index];
		buff_size--;
		index++;
	}
	if (buff_size != 0)
	{
		dst[index] = '\0';
	}
	return (ft_strlen(src));
}

/*
#include<stdio.h>
int main(void)
{
	char str[15] = "learning";
	char dest[15] = "";
    printf("\"%s\"", dest);
	ft_strlcpy(dest, str, 3);
	printf("\"%s\"", dest);
}
*/
