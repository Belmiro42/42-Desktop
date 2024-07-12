/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:40:01 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/04/13 23:20:40 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	char	character;

	while (*str)
	{
		character = *str;
		write(1, &character, 1);
		str++;
	}
}

/*
int main(void)
{
	char stree[] = "hey yhere";
	ft_putstr(stree);
	return(0);
}
*/
