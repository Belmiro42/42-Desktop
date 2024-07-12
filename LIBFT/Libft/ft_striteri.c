/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:44:42 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/03/31 16:37:15 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *string, void (*f)(unsigned int, char*))
{
	unsigned int	index;

	if (!string)
		return ;
	index = -1;
	while (string[++index])
		f(index, &string[index]);
}
