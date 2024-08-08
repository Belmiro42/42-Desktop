/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:11:37 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/08 16:57:21 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_p_recursive(void *puntero,
			unsigned int *index, unsigned int *length)
{
	char	*digits;
	unsigned int	number;

	number = (unsigned int)puntero;
	digits = "0123456789abcdef";
	if ((number / 16) == 0)
	{
		*length += write(1, "0x", 2);
		*length += write(1, &digits[number % 16], 1);
		*index += 2;
		return ;
	}
	do_p((void *)(number / 16), index, length);
	*length += write(1, &digits[number % 16], 1);
}

void	do_p(void *puntero, unsigned int *index, unsigned int *length)
{
	if (puntero == NULL)
	{
		*length += write(1, "(nil)", 5);
		*index += 2;
		return ;
	}
	do_p_recursive(puntero, index, length);
}
