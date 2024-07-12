/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:50:50 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/03/28 20:01:58 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	index;

	index = ft_strlen(s) + 1;
	while (index--)
	{
		if (*(s + index) == (char)c)
			return ((char *)(s + index));
	}
	return (NULL);
}

/*
int main()
{
	char str[] = "asasd";
	char *s;
	char p;
	s = ft_strchr(str, 'd');
	p = *s;
	write(1, &p, 1);
}
*/
