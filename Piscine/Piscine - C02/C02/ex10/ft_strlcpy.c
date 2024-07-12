/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:13:14 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/04/12 23:47:47 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
//#include <stdio.h>

int	ft_strlcpy(char *dst, const char *src, int buff_size)
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
	while (src[index] != '\0')
		index++;
	return (index);
}

/*
int main() {
    char myString[] = "salut, commAKSDn"; 
    char dest[42];
    int length = ft_strlcpy(dest, myString, sizeof(dest));
    printf("Source: %s\n", myString);
    printf("Destination: %s\n", dest);
    printf("Length: %d\n", length);

    return 0;
}
*/
