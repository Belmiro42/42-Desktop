/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Move_Rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:36:51 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/03 01:03:05 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_______CORE/Push_Swap.h"

void	ra(t_node **stack, bool print)
{
	if (len_stack(*stack) > 1)
	{
		(*stack) = (*stack)->prev;
		(*stack)->next->next = get_last(*stack, 0);
		(*stack)->next->next->prev = (*stack)->next;
		(*stack)->next->prev = NULL;
		(*stack)->next = NULL;
		if (print)
			(void)write(1, "ra\n", 3);
	}
}

void	rb(t_node **stack, bool print)
{
	if (len_stack(*stack) > 1)
	{
		(*stack) = (*stack)->next;
		(*stack)->prev->prev = get_last(*stack, 1);
		(*stack)->prev->prev->next = (*stack)->prev;
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
		if (print)
			(void)write(1, "rb\n", 3);
	}
}

void	rr(t_node **stack_a, t_node **stack_b, bool print)
{
	if (len_stack(*stack_a) >= 2 && len_stack(*stack_b) >= 2)
	{
		ra(stack_a, 0);
		rb(stack_b, 0);
		if (print)
			(void)write(1, "rr\n", 3);
	}
}
