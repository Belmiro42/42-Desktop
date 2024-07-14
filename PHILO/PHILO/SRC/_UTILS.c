/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _UTILS.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:44:22 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/14 02:07:41 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 	UTILS									│
//  ├───────────────────────────────────────────────────────────────────────┤
size_t	phil_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

size_t	phil_strlcpy(char *dst, const char *src, size_t buff_size)
{
	size_t	index;

	index = 0;
	if (buff_size == 0)
		return (phil_strlen(src));
	while (buff_size > 1 && src[index])
	{
		dst[index] = src[index];
		buff_size--;
		index++;
	}
	if (buff_size != 0)
		dst[index] = '\0';
	return (phil_strlen(src));
}

size_t	phil_strlcat(char *dst, const char *src, size_t buff_size)
{
	size_t	dst_len;
	size_t	src_len;

	src_len = phil_strlen(src);
	dst_len = phil_strlen(dst);
	if (buff_size <= dst_len)
		return (buff_size + src_len);
	return (dst_len + phil_strlcpy(dst + dst_len, src, buff_size - dst_len));
}

long unsigned	get_time(void)
{
	struct timeval	now;

	gettimeofday(&now, 0);
	return ((now.tv_sec * 1000000) + now.tv_usec);
}

int	phil_atoi(char **argv, int c)
{
	long	number;
	char	*str;

	str = argv[c];
	if (str == NULL)
		return (0);
	number = 0;
	while ((48 <= *str && *str <= 57))
	{
		number = number * 10 + (*str++ - '0');
		if (number > INT_MAX || number == 0)
		{
			free_string(argv);
			my_exit(NULL);
		}
	}
	if (*str)
	{
		free_string(argv);
		my_exit(NULL);
	}
	return (number);
}
