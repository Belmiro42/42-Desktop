/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:34:24 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/21 06:46:14 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	char	*iter;

	iter = str;
	while (*iter != '\0')
	{
		if (*iter < 'A' || (*iter > 'Z' && *iter < 'a') || *iter > 'z')
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
    char myString[] = "ABSa"; 
    if (ft_str_is_alpha(myString)) 
    {
        printf("%s contains only alphabetic characters.\n", myString);
    } 
    else 
    
    {
        printf("%s contains non-alphabetic characters.\n", myString);
    }

    return 0;
}
*/
