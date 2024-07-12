/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 01:32:32 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/06/09 13:46:50 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	if (n == 0)
		return (0);
	index = 0;
	while (s1[index] == s2[index] && s1[index] && index < n - 1)
	{
		index ++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}


int main()
{
	char c;

	int b = 5;
	char *s1= "aaaaaa";
	char *s2= "aaaa";
	c = strncmp(s1, s2, b) + '0';
	write(1, &c, 1);
	write(1, "\n", 1);
	char s3[]= "aaaaaa";
	char s4[]= "aaaa";
	c = strncmp(s3, s4, b) + '0';
	write(1, &c, 1);	
}
