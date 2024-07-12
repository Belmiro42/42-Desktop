/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:16:56 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/04/12 23:52:33 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *iter)
{
	char		character;
	const char	*hexdigits = "0123456789abcdef";
	char		output[3];

	while (*(iter) != '\0')
	{
		if (*iter < 32 || *iter == 127)
		{
			output[0] = '\\';
			output[1] = hexdigits[(*iter >> 4) & 0xF];
			output[2] = hexdigits[*iter & 0xF];
			write(1, output, 3);
		}
		else
		{
			character = *iter;
			write(1, &character, 1);
		}
		iter++;
	}
}

/*
int main() {
    char str[] = "salut, comm\nAKSn"; 
    ft_putstr_non_printable(str);
    return 0;
}
*/
