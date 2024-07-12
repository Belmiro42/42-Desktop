/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:41:43 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/03/16 20:11:10 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	int		len;
	char	*str2;

	len = ft_strlen(str1);
	str2 = malloc(len + 1);
	if (str2 == NULL)
		return (NULL);
	ft_strlcpy(str2, str1, len + 1);
	return (str2);
}

/*
#include <string.h>
#include <assert.h>
#include <stdlib.h>
 
int main(void)
{
    const char *s1 = "String";
    char *s2 = ft_strdup(s1);
    assert(strcmp(s1, s2) == 0);
    free(s2);
}
*/