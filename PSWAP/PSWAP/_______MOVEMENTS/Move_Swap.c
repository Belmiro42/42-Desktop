/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move_Swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:11:11 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/03 01:03:07 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_______CORE/Push_Swap.h"

void	sa(t_node **stack, bool print)
{
	if (len_stack(*stack) > 1)
	{
		(*stack)->next = (*stack)->prev;
		(*stack)->prev = (*stack)->prev->prev;
		(*stack)->next->prev = *stack;
		(*stack)->next->next = NULL;
		if ((*stack)->prev)
			(*stack)->prev->next = *stack;
		*stack = (*stack)->next;
		if (print)
			(void)write(1, "sa\n", 3);
	}
}

void	sb(t_node **stack, bool print)
{
	if (len_stack(*stack) > 1)
	{
		(*stack)->prev = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		(*stack)->prev->next = *stack;
		(*stack)->prev->prev = NULL;
		if ((*stack)->next)
			(*stack)->next->prev = *stack;
		*stack = (*stack)->prev;
		if (print)
			(void)write(1, "sb\n", 3);
	}
}

void	ss(t_node **stack_a, t_node **stack_b, bool print)
{
	if (len_stack(*stack_a) > 1 && len_stack(*stack_b) > 1)
	{
		sa(stack_a, 0);
		sb(stack_b, 0);
		if (print)
			(void)write(1, "ss\n", 3);
	}
}
