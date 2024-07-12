/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:42:18 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/21 06:48:43 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	char	*iter;

	iter = str;
	while (*iter != '\0')
	{
		if (*iter > '9' || *iter < '0')
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
    char myString[] = "1234a51"; 
    if (ft_str_is_numeric(myString)) 
    {
        printf("%s contains only numeric characters.\n", myString);
    } 
    else 
    
    {
        printf("%s contains non-numeric characters.\n", myString);
    }

    return 0;
}
*/
