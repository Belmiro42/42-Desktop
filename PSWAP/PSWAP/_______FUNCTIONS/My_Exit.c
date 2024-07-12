/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   My_Exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:09:14 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/03 01:02:50 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_______CORE/Push_Swap.h"

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 	MY_EXIT									│
//  ├───────────────────────────────────────────────────────────────────────┤
//	│ Iterates through Stack A and Stack B and frees each node.				│
//	│ You need the temp because freeing the node eliminates the next pointer│
// 	│ I use my exit to end the program and free all the files simultaneuosly|
//  └───────────────────────────────────────────────────────────────────────┘ 
void	my_exit(char *str, t_node *stack_prev_dir,
		t_node *stack_next_dir, int ERROR)
{
	t_node	*temp;

	(void)str;
	temp = stack_next_dir;
	while (temp)
	{
		stack_next_dir = stack_next_dir->next;
		free(temp);
		temp = stack_next_dir;
	}
	temp = stack_prev_dir;
	while (temp)
	{
		stack_prev_dir = stack_prev_dir->prev;
		free(temp);
		temp = stack_prev_dir;
	}
	if (ERROR)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void	word_number_check(int word_number, int *letter)
{
	*letter = 0;
	if (word_number == 4999)
		my_exit("TOO MANY ARGUMENTS", NULL, NULL, 1);
}

void	arg_check(char **argv, int argc)
{
	int		index;
	bool	no_int;

	while (--argc >= 0)
	{
		index = -1;
		no_int = 1;
		while (argv[argc][++index])
			if (argv[argc][index] < 58 && argv[argc][index] > 47)
				no_int = 0;
		if (no_int)
			my_exit("A PARAMETER HAS NO NUMBERS IN", NULL, NULL, 1);
	}
}
