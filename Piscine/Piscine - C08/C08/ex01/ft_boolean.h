/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 00:48:36 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/03/01 01:35:27 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int EVEN(int a)
{
	return ((a%2)) == 0 ? 1 : 0;
}

typedef int t_bool;

#define EVEN_MSG "FUCK YEAH"
#define ODD_MSG "FUCK NO"
#define SUCCESS 0
#define TRUE 1
#define FALSE 0

