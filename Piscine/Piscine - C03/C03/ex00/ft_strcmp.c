/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:17:18 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/04/12 23:55:02 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	char	*cpy1;
	char	*cpy2;

	cpy1 = s1;
	cpy2 = s2;
	while (*cpy1 != '\0' && *cpy2 != '\0' && *cpy1 == *cpy2)
	{
		cpy1++;
		cpy2++;
	}
	return (*s1 - *s2);
}

/*
int main() {
    char str1[] = "worldly";
    char str2[] = "world";
    int result = ft_strcmp(str1, str2);

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
