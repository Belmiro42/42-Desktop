/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:31:57 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/21 06:42:56 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, int n)
{
	char	*dest_start;

	dest_start = dest;
	while (n > 0 && *src != '\0')
	{
		*dest++ = *src++;
		--n;
	}
	while (n > 0)
	{
		*dest++ = '\0';
		--n;
	}
	return (dest_start);
}

/*
int main() {
    char source[] = "Hello, World!";
    char destination[] = "asdasdfasdf";

    ft_strncpy(destination, source, 7);

    printf(" %s\n", destination);

    return 0;
}
*/
