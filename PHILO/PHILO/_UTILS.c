/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UTILS.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:44:22 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/12 22:17:39 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 	UTILS									│
//  ├───────────────────────────────────────────────────────────────────────┤
size_t phil_strlen(const char *s)
{
	size_t index = 0;
	while (s[index])
		index++;
	return index;
}
size_t phil_strlcpy(char *dst, const char *src, size_t buff_size) 
{
	size_t index = 0;
	if (buff_size == 0)
		return phil_strlen(src);
	while (buff_size > 1 && src[index]) {
		dst[index] = src[index];
		buff_size--;
		index++;
	}
	if (buff_size != 0)
		dst[index] = '\0';
	return phil_strlen(src);
}
size_t phil_strlcat(char *dst, const char *src, size_t buff_size) 
{
	size_t dst_len = phil_strlen(dst);
	size_t src_len = phil_strlen(src);

	if (buff_size <= dst_len)
		return buff_size + src_len;

	return dst_len + phil_strlcpy(dst + dst_len, src, buff_size - dst_len);
}
long unsigned get_time()
{
	struct timeval now;

	gettimeofday(&now, 0);
	return ((now.tv_sec * 1000000) + now.tv_usec);	
}