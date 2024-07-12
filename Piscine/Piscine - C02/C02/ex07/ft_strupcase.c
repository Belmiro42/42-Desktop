/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:00:43 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/21 07:03:29 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strupcase(char *str)
{
	char	*iter;

	iter = str;
	while (*iter != '\0')
	{
		if (*iter >= 'a' && *iter <= 'z')
		{
			*iter -= 32;
		}
		iter++;
	}
	return (str);
}

/*
int main() 
{
    char myString[] = "Hellqw123oWorld";

    printf("Original string: %s\n", myString);

   ft_strupcase(myString);

    printf("Uppercase string: %s\n", myString);

    return 0;
}
*/
