/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 00:05:26 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/03/30 19:21:11 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, size_t buff_size)
{
	size_t	index;
	size_t	ret;

	index = 0;
	while (*dst && index < buff_size)
	{
		++dst;
		++index;
	}
	ret = ft_strlcpy(dst, src, buff_size - index);
	return (ret + index);
}

/*
int main(void)
{
    char str[] = "abc";
	char str2[] = "def";
	puts(str);
	ft_strlcat(str, str2, 7);
	puts(str);
}
*/