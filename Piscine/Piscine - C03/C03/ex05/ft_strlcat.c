/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:25:34 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/04/13 23:15:19 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_index;
	unsigned int	src_index;

	dest_index = 0;
	src_index = 0;
	while (dest[dest_index])
		dest_index++;
	while (src[src_index] && size > 1)
		dest[dest_index++] = src[src_index++];
	dest[dest_index] = '\0';
	while (src[src_index++] != '\0')
		dest_index++;
	return (dest_index);
}

/*
#include <stdio.h>
#include <string.h>

int main() {
    char dest[20] = "Hello, ";
    char *src = "worasanskldgnlanlkgld!";

    size_t result = ft_strlcat(dest, src, 20);

    printf("Concatenated string: %s\n", dest);
    printf("Total length after concatenation: %zu\n", result);

    return 0;
}
*/
