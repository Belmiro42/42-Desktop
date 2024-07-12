/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utimate_div_mod.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:07:23 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/13 19:06:58 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *a / *b;
	*b = *a % *b;
	*a = temp;
}

/*
int main()
{
    int a =52;
    int b =10;
    ft_ultimate_div_mod(&a, &b);
    a += '0';
    b += '0';
    write(1, &a, 1);
    write(1, &b, 1);
}
*/
