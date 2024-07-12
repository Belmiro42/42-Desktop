/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:05:35 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/21 07:05:53 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	char	*iter;

	iter = str;
	while (*iter != '\0')
	{
		if (*iter >= 'A' && *iter <= 'Z')
		{
			*iter += 32;
		}
		iter++;
	}
	return (str);
}

/*
int main() {
    char myString[] = "Hellqw123oWorld";

    printf("Original string: %s\n", myString);

   ft_strlowcase(myString);

    printf("Uppercase string: %s\n", myString);

    return 0;
}
*/
