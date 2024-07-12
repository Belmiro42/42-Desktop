/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:48:09 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/21 06:55:40 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	char	*iter;

	iter = str;
	while (*iter != '\0')
	{
		if (*iter > 'Z' || *iter < 'A')
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
    char myString[] = "MAisS";
    if (ft_str_is_uppercase(myString))
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
