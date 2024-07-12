/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:29:25 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/04/12 23:59:36 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	char	*cpy1;
	char	*cpy2;

	cpy1 = s1;
	cpy2 = s2;
	while ((*cpy1 != '\0') && (*cpy2 != '\0') && (*cpy1 == *cpy2) && (n > 1))
	{
		cpy1++;
		cpy2++;
		n--;
	}
	return (*cpy1 - *cpy2);
}
/*
int main() {
    char str1[] = "worldly";
    char str2[] = "world";
    int result = ft_strncmp(str1, str2, 6);

    if (result == 0) {
        printf("The strings are equal.\n");
    } else if (result < 0) {
        printf("str1 is less than str2.\n");
    } else {
        printf("str1 is greater than str2.\n");
    }

    return 0;
}
*/
