/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:51:31 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/04/12 09:56:46 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	char	*iter;

	iter = str;
	if (*str == '\0')
		return (1);
	while (*iter != '\0')
	{
		if (*iter < 32 || *iter > 126)
		{
			return (0);
		}
		iter++;
	}
	return (1);
}

/*
int main()
{
    char myString[] = "MASS";
    if (ft_str_is_printable(myString))
    {
        printf("%s contains only  characters.\n", myString);
    }
    else

    {
        printf("%s contains non characters.\n", myString);
    }

    return 0;
}

*/
