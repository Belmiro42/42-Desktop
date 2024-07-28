/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:47:08 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/23 19:48:19 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 	DISPLAY									│
//  ├───────────────────────────────────────────────────────────────────────┤
//	│ Displays the stacks in the following format:  						│
// 	│ Bottom Of Stack A -> Top Stack A -> █ -> Top Stack B -> Bottom Stk B	│
//  └───────────────────────────────────────────────────────────────────────┘ 
/*
static void	display(t_node *stack_a, t_node *stack_b)
{
	printf("\n");
	if (len_stack(stack_b) > 0)
		stack_b = get_last(stack_b, 0);
	while (stack_a)
	{
		printf(" %d ", stack_a->value);
		stack_a = stack_a->prev;
	}
	printf(" █ ");
	while (stack_b)
	{
		printf(" %d ", stack_b->value);
		stack_b = stack_b->next;
	}
	printf("\n\n\n");
}*/

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							  CHECK LINKS	(Legacy Code (Still Useful))│
//  ├───────────────────────────────────────────────────────────────────────┤
//	│ Displays the vertically with the prev / next pointer value on either 	│
//	│ side.  																│
//  └───────────────────────────────────────────────────────────────────────┘ 
/* 
static void check_links_a(t_node *stack)
{
	int vp;
	int vn;
	t_node *temp;

	printf("### STACK A ###");
	while(stack)
	{
		if (!stack->prev)
			vp = 0;
		else
			vp = stack->prev->value;
		if (!stack->next)
			vn = 0;
		else
			vn = stack->next->value;
		printf("%d ──────── %d ─────── %d\n", vn, stack->value, vp);
		temp = stack;
		stack = stack->prev;
	}
}
static void check_links_b(t_node *stack)
{
	int vp;
	int vn;
	t_node *temp;

	printf("### STACK B ###");
	while(stack)
	{
		if (!stack->prev)
			vp = 0;
		else
			vp = stack->prev->value;
		if (!stack->next)
			vn = 0;
		else
			vn = stack->next->value;
		printf("%d ├──────── %d ───────┤ %d\n", vp, stack->value, vn);
		temp = stack;
		stack = stack->next;
	}
}
*/
//
//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 	MY_EXIT									│
//  ├───────────────────────────────────────────────────────────────────────┤
//	│ Throughout the code we have my_exit function which we pass a string to│
//	│ These do not print to conform to assessment standards but makes it    │
// 	│ much easier to identify what the error is, if you do print. Also frees│
//  └───────────────────────────────────────────────────────────────────────┘
//
int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc == 1)
		my_exit("NO ARGUMENTS PASSED", NULL, NULL, 0);
	stack_a = make_stack(argc, argv + 1);
	stack_b = NULL;
	index_stack(stack_a);
	//display(stack_a, stack_b);
	sort(&stack_a, &stack_b);
	//display(stack_a, stack_b);
	my_exit("END OF THE PROGRAM", stack_a, stack_b, 0);
}
