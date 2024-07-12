/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:45:17 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/21 06:52:57 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	char	*iter;

	iter = str;
	while (*iter != '\0')
	{
		if (*iter > 'z' || *iter < 'a')
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
    char myString[] = "aMss"; 
    if (ft_str_is_lowercase(myString)) 
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
