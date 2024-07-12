/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:36:30 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/03/20 18:05:48 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(unsigned short c)
{
	if (48 <= c && c <= 57)
	{
		return (1);
	}
	return (0);
}

/*
int main(void)
{
	char c;
	c = '2';
	if (ft_isdigit(c))
	{
		write (1, "FUCKYEAH", 8);
	}
}
*/
