/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 21:49:30 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/04/02 10:55:43 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index++])
		;
	return (index - 1);
}

/*
int main()
{
	char str[] = "fuckyeah";
	char c = ft_strlen(str) + '0';
	write(1, &c, 1);	
}
*/
