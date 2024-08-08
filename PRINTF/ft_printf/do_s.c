/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:13:26 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/08 16:48:18 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_s(char *c, unsigned int *index, unsigned int *length)
{
	unsigned int	index_s;

	index_s = 0;
	if (c == NULL)
		*length += write(1, "(null)", 6);
	while (c[index_s])
		(*length) += write(1, &c[index_s++], 1);
	*index += 2;
}
