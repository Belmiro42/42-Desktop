/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:07:41 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/04/12 23:47:22 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcapitalize(char *str)
char	*ft_strcapitalize(char *str)
{
	int		checkb;
	int		index;
	char	p;

	index = -1;
	checkb = 1;
	while (str[++index] != '\0')
	{
		if ((index == 0) && (str[index] > 'a' && str[index] < 'z'))
			str[index] -= 32;
		if (index > 0)
		{
			p = str[index - 1];
			if (!(p <= '9' && p >= '0') && !((p >= 'A' && p <= 'Z')
					|| (p >= 'a' && p <= 'z')))
			{
				if (str[index] >= 'a' && str[index] <= 'z')
					str[index] -= 32;
			}
			else
				if ((str[index] >= 'A' && str[index] <= 'Z'))
					str[index] += 32;
		}
	}
	return (str);
}

/*
int main() {
    char myString[] = "salut, commAKSDJent t";

    printf("Original string: %s\n", myString);

   ft_strcapitalize(myString);

    printf("Uppercase string: %s\n", myString);

    return 0;
}
*/
