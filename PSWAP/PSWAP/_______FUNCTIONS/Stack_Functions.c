/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_Functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:19:25 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/03 01:02:57 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_______CORE/Push_Swap.h"

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 NODE DISTANCE								│
//  └───────────────────────────────────────────────────────────────────────┘
void	index_stack(t_node *stack)
{
	t_node	*iterator;

	while (stack)
	{
		iterator = stack->prev;
		while (iterator)
		{
			if (iterator->value > stack->value)
				iterator->index += 1;
			else
				stack->index += 1;
			iterator = iterator->prev;
		}
		stack = stack->prev;
	}
}

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 LEN STACK									│
//  └───────────────────────────────────────────────────────────────────────┘
int	len_stack(t_node *stack)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		count;

	stack_a = stack;
	stack_b = stack;
	count = 0;
	while (stack_a)
	{
		stack_a = stack_a->prev;
		count++;
	}
	while (stack_b)
	{
		stack_b = stack_b->next;
		count++;
	}
	return (count - 1);
}

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 NODE DISTANCE								│
//  └───────────────────────────────────────────────────────────────────────┘
t_node	*get_last(t_node *stack, int direction)
{
	t_node	*last;

	if (!stack)
		my_exit("Called Get Last With Empty Stack", NULL, NULL, 1);
	while (stack)
	{
		last = stack;
		if (direction == 0)
			stack = stack->prev;
		else
			stack = stack->next;
	}
	return (last);
}

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 SQUARE ROOT								│
//  ├──────────────────────────────────────────┬────────────────────────────┘
//	│⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⣀⣀⣀⣀⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	│
//	│⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	│
//	│⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	│
//	│⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	│
//	│⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	│
//	│⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣿⣦⡀⠀⠀⠀⠀⠀	│
//	│⠀⠀⠀⠀⠀⢀⣴⣿⣿⠿⠛⠻⢿⣿⣿⣿⣿⣿⣿⡿⠟⠛⢻⣿⣿⣧⡀⠀⠀⠀⠀	│
//	│⠀⠀⠀⠀⢠⣿⡿⠋⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⡇⠀⠐⣿⡟⠈⢿⣷⡄⠀⠀⠀	│
//	│⠀⠀⠀⣰⡿⠿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣿⡇⠀⠀⠈⢳⠀⠀⢿⡿⠦⠄⠀	│
//	│⠀⠀⠠⠋⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠘⣿⠀⠀⠀	│
//	│⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⣰⡇⠀⠀⠀	│
//	│⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⣿⣿⣟⡀⠀⠀⠀⠀⠀⠀⣰⠟⠀⠀⠀⠀	│
//	│⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣴⣿⠟⠋⠁⠀⠈⠙⢻⣶⡄⠀⠀⠀⠈⠁⠀⠀⠀⠀⠀	│
//	│⠀⠀⠀⠀⠀⠀⠀⠈⠁⠀⢸⡇⠀⠀⠀⠀⠀⠐⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	│
//	│⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  	|
//  └──────────────────────────────────────────┘ 
int	ps_sqrt(int sq)
{
	int	i;

	i = 0;
	while (1)
	{
		if ((i * i) == sq)
			return (i);
		if ((i * i) < sq && ((i + 1) * (i + 1)) > sq)
			return (i);
		i++;
	}
}

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 NODE DISTANCE								│
//  ├───────────────────────────────────────────────────────────────────────┤
//	│Returns the distance between top of stack and an index using rotate.	|
//  └───────────────────────────────────────────────────────────────────────┘ 
int	node_distance(t_node *stack_a, t_node *stack_b, int index)
{
	int	count;

	count = 0;
	if (stack_b)
	{
		while (stack_b->index != index)
		{
			stack_b = stack_b->next;
			count++;
		}
	}
	if (stack_a)
	{
		while (stack_a->index != index)
		{
			stack_a = stack_a->prev;
			count++;
		}
	}
	return (count);
}
