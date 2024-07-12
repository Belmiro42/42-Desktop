/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:11:03 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/05/02 19:45:21 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_x(unsigned int number, char c,
				unsigned int *index, unsigned int *length)
{
	char	*digits;

	digits = "0123456789abcdef";
	if (c == 'X')
		digits = "0123456789ABCDEF";
	if ((number / 16) == 0)
	{
		*length += write(1, &digits[number % 16], 1);
		*index += 2;
		return ;
	}
	do_x((number / 16), c, index, length);
	*length += write(1, & digits[number % 16], 1);
}
