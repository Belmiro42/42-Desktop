/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move_Push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:36:54 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/03 01:03:01 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_______CORE/Push_Swap.h"

void	pb(t_node **a, t_node **b, bool print)
{
	t_node	*temp;

	if (len_stack(*a) > 0)
	{
		temp = *a;
		*a = temp->prev;
		temp->next = *b;
		if (*a)
			(*a)->next = NULL;
		if (*b)
			(*b)->prev = temp;
		temp->prev = NULL;
		*b = temp;
		if (print)
			(void)write(1, "pb\n", 3);
	}
}

void	pa(t_node **a, t_node **b, bool print)
{
	t_node	*temp;

	if (len_stack(*b) > 0)
	{
		temp = *b;
		*b = temp->next;
		temp->prev = *a;
		if (*b)
			(*b)->prev = NULL;
		if (*a)
			(*a)->next = temp;
		temp->next = NULL;
		*a = temp;
		if (print)
			(void)write(1, "pa\n", 3);
	}
}
