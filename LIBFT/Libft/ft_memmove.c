/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 23:19:38 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/03/20 17:01:12 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*ret;

	if (!dst && !src)
		return (0);
	ret = dst;
	if (src < dst)
	{
		src += len;
		dst += len;
		while (len--)
			*(char *)--dst = *(char *)--src;
	}
	else
		while (len--)
			*(char *)dst++ = *(char *)src++;
	return (ret);
}
/*
int main () {
   char dest[] = "oldstring";
   const char src[]  = "newstring";
   printf("Before memmove dest = %s, src = %s\n", dest, src);
   ft_memmove(dest, src, 10);
   printf("After memmove dest = %s, src = %s\n", dest, src);
   return(0);
}
*/
