/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_Functions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 02:42:20 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/03 01:02:54 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_______CORE/Push_Swap.h"

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 IS SORTED									│
//  ├───────────────────────────────────────────────────────────────────────┤
//	│ Checks all nodes are in order. Wierdly this is only used at the start.|
//  └───────────────────────────────────────────────────────────────────────┘ 
bool	is_sorted(t_node *stack_a)
{
	int	index;

	index = -1;
	while (stack_a)
	{
		if (stack_a->index < index)
			return (false);
		index = stack_a->index;
		stack_a = stack_a->prev;
	}
	return (true);
}

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 GET MIN									│
//  ├───────────────────────────────────────────────────────────────────────┤
//	│ Finds the smallest index in the stack. Value starts at max-int because|
//	│ we need the largest number possible. If you put in  2147483647 		|
//	│ values this wont crash as this is only run to find mins so it should  |
//	│ find every value smaller than the largest value and return it. When 	|
//	│ the largest value is alone it returns itself. Good job get min.   	|
//  └───────────────────────────────────────────────────────────────────────┘ 
int	get_min(t_node *stack)
{
	int	value;

	value = 2147483647;
	while (stack)
	{
		if (stack->index < value)
			value = stack->index;
		stack = stack->prev;
	}
	return (value);
}

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 RESET_INDEX								│
//  ├───────────────────────────────────────────────────────────────────────┤
//	│ All indexes to zero.													|
//  └───────────────────────────────────────────────────────────────────────┘ 
void	reset_index(t_node *stack)
{
	while (stack)
	{
		stack->index = 0;
		stack = stack->prev;
	}
}

bool	bels_isspace(char ch)
{
	if (ch == 32 || (13 >= ch && ch >= 9))
		return (1);
	return (0);
}
