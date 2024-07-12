/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:43:26 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/03/31 16:37:40 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//NULL IF ALLOCATION FAILS

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, len + 1);
	ft_strlcat(ptr, s2, len + 1);
	return (ptr);
}

/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main() 
{
    const char *s1 = "Hello, ";
    const char *s2 = "world!";
    char *joined = ft_strjoin(s1, s2);

    if (joined != NULL) {
        // Print the joined string
        printf("%s\n", joined);

        // Free the allocated memory
        free(joined);
    } else {
        // Handle memory allocation failure
        printf("Memory allocation failed\n");
        return 1;
    }

    return 0;
}
*/