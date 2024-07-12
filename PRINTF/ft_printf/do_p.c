/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:11:37 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/06/19 19:00:15 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	do_p_forealsies(void *puntero,
			unsigned int *index, unsigned int *length)
{
	char	*digits;
	size_t	number;

	number = (size_t)puntero;
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

void	do_p(void *poop, unsigned int *index, unsigned int *length)
{
	if (poop == NULL)
	{
		*length += write(1, "(nil)", 5);
		*index += 2;
		return ;
	}
	do_p_forealsies(poop, index, length);
}
