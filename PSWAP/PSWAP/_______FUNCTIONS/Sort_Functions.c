/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sort_Functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 01:00:44 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/03 01:02:52 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_______CORE/Push_Swap.h"

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 	K-SORT									│
//  ├───────────────────────────────────────────────────────────────────────┤
//	│ These can be looked up but I'll mention complexity is the reason why	│
//	│ each one is selected.													│
//	│ KSORT or Dual Pivot Quicksort has a complexity of O(0.8*n*log(n))		│
//	│•••••••••••••••••••••••••••• 											│
//	│•••[•♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥•]•••• The K comes from the way the values are	│
//	│•••[•♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥•]•••••• sorted creating a K shape where one of 	│
//	│•••[•♥♥♥♥♥♥♥♥♥♥♥♥•]••••••••• the arms has proportionally larger values.│
//	│•••[•♥♥♥♥♥♥♥♥♥♥•]••••••••••• than the other.							│
//	│•••[•♥♥♥♥♥♥♥♥•]•••••••••••••											│
//	│•••[•♥♥♥♥♥♥•]••••••••••••••• This is faster than quick sort making it 	│
//	│•••[•♥♥♥♥♥♥♥♥♥•]•••••••••••• useful for large number volumes.			│
//	│•••[•♥♥♥♥♥♥♥♥♥♥♥•]•••••••••• 											│
//	│•••[•♥♥♥♥♥♥♥♥♥♥♥♥♥•]•••••••• The seperation of values mean that 		│
//	│•••[•♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥•]•••••• finding values to push back to the 		│
//	│•••[•♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥•]•••• original stack is faster.					│
//	│••[•♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥•]•											│
//	│••••••••••••••••••••••••••••											│
//  └───────────────────────────────────────────────────────────────────────┘ 
static void	k_sort_(t_node **stack_a, t_node **stack_b, int length)
{
	int	rb_distance;
	int	rrb_distance;

	while (length - 1 >= 0)
	{
		rb_distance = node_distance(NULL, *stack_b, length - 1);
		rrb_distance = (length + 3) - rb_distance;
		if (rb_distance <= rrb_distance)
		{
			while ((*stack_b)->index != length - 1)
				rb(stack_b, 1);
			pa(stack_a, stack_b, 1);
			length--;
		}
		else
		{
			while ((*stack_b)->index != (length - 1))
				rrb(stack_b, 1);
			pa(stack_a, stack_b, 1);
			length--;
		}
	}
}

static void	k_sort(t_node **stack_a, t_node **stack_b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ps_sqrt(length) * 14 / 10;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b, 1);
			rb(stack_b, 1);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			pb(stack_a, stack_b, 1);
			i++;
		}
		else
			ra(stack_a, 1);
	}
	k_sort_(stack_a, stack_b, length);
}

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 3 Value Sort								│
//  ├───────────────────────────────────────────────────────────────────────┤
//	│ Just sorting three values manually as algorithms for this suck		|
//  └───────────────────────────────────────────────────────────────────────┘ 
static void	simple_sort(t_node **stack)
{
	reset_index(*stack);
	index_stack(*stack);
	if ((*stack)->index == 1 && (*stack)->prev->index == 0)
		sa(stack, 1);
	if ((*stack)->index == 1 && (*stack)->prev->index == 2)
		rra(stack, 1);
	if ((*stack)->index == 2 && (*stack)->prev->index == 0)
		ra(stack, 1);
	if ((*stack)->index == 2 && (*stack)->prev->index == 1)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	if ((*stack)->index == 0 && (*stack)->prev->index == 2)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
}

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							INSERTION SORT								│
//  ├───────────────────────────────────────────────────────────────────────┤
//	│ Insertion sort finds the shortest path for the smallest value into	|
//	│ stack B and pushes to stack B. Repeats. When sorted push to A			|
//  └───────────────────────────────────────────────────────────────────────┘ 
static void	insertion_sort(t_node **stack_a, t_node **stack_b, int length)
{
	int	min_index;
	int	iter;
	int	n;

	iter = 0;
	n = length;
	while (len_stack(*stack_a) != 3)
	{
		min_index = get_min(*stack_a);
		if (node_distance(*stack_a, NULL, min_index) <= n - min_index
			- node_distance(*stack_a, NULL, min_index))
			while ((*stack_a)->index != min_index)
				ra(stack_a, 1);
		else
			while ((*stack_a)->index != min_index)
				rra(stack_a, 1);
		if (is_sorted(*stack_a) && len_stack(*stack_b) == 0)
			return ;
		pb(stack_a, stack_b, 1);
		length--;
	}
	simple_sort(stack_a);
	iter = 0;
	while (iter++ < n - 3)
		pa(stack_a, stack_b, 1);
}

void	sort(t_node **stack_a, t_node **stack_b)
{
	if (is_sorted(*stack_a))
	{
		my_exit("Stacks Sorted", *stack_a, *stack_b, 0);
	}
	if (len_stack(*stack_a) == 2)
		sa(stack_a, 1);
	else if (len_stack(*stack_a) == 3)
		simple_sort(stack_a);
	else if (len_stack(*stack_a) < 7)
		insertion_sort(stack_a, stack_b, len_stack(*stack_a));
	else
		k_sort(stack_a, stack_b, len_stack(*stack_a));
}
