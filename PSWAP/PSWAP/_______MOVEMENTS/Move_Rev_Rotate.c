/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move_Rev_Rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:36:42 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/03 01:03:03 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_______CORE/Push_Swap.h"

void	rra(t_node **stack, bool print)
{
	if (len_stack(*stack) >= 2)
	{
		(*stack)->next = get_last(*stack, 0);
		(*stack)->next->prev = *stack;
		(*stack)->next->next->prev = NULL;
		(*stack)->next->next = NULL;
		(*stack) = (*stack)->next;
		if (print)
			(void)write(1, "rra\n", 4);
	}
}

void	rrb(t_node **stack, bool print)
{
	if (len_stack(*stack) >= 2)
	{
		(*stack)->prev = get_last(*stack, 1);
		(*stack)->prev->prev->next = NULL;
		(*stack)->prev->prev = NULL;
		(*stack)->prev->next = *stack;
		(*stack) = (*stack)->prev;
		if (print)
			(void)write(1, "rrb\n", 4);
	}
}

void	rrr(t_node **stack_a, t_node **stack_b, bool print)
{
	if (len_stack(*stack_a) >= 2 && len_stack(*stack_b) >= 2)
	{
		rra(stack_a, 0);
		rrb(stack_b, 0);
		if (print)
			(void)write(1, "rrr\n", 4);
	}
}
