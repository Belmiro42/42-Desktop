/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:09:12 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/02 23:34:54 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  ┌──────────────────────────────────────────────────────────────────────────┐
//  │								INCLUDES							       │
//  └──────────────────────────────────────────────────────────────────────────┘
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <unistd.h>

//  ┌──────────────────────────────────────────────────────────────────────────┐
//  │								STRUCT									   │
//  └──────────────────────────────────────────────────────────────────────────┘
typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				index;
	int				value;
}	t_node;

//  ┌──────────────────────────────────────────────────────────────────────────┐
//  │							   MOVEMENTS								   │
//  └──────────────────────────────────────────────────────────────────────────┘
																//PUSH
void	pa(t_node **b, t_node **a, bool print);
void	pb(t_node **a, t_node **b, bool print);
																//SWAP
void	sa(t_node **stack, bool print);
void	sb(t_node **stack, bool print);
void	ss(t_node **stack1, t_node **stack2, bool print);
																//ROTATE
void	ra(t_node **stack, bool print);
void	rb(t_node **stack, bool print);
void	rr(t_node **stack1, t_node **stack2, bool print);
																//REVERSE ROTATE
void	rra(t_node **stack, bool print);
void	rrb(t_node **stack, bool print);
void	rrr(t_node **stack1, t_node **stack2, bool print);

//  ┌──────────────────────────────────────────────────────────────────────────┐
//  │							 EVERYTHING ELSE							   │
//  └──────────────────────────────────────────────────────────────────────────┘
															//STACK 
																//MANIPULATION
t_node	*make_stack(int argc, char **argv);
void	sort(t_node **stack_a, t_node **stack_b);
void	reset_index(t_node *stack);
void	index_stack(t_node *stack);
void	arg_check(char **argv, int argc);
bool	bels_isspace(char ch);
																//GET DATA
int		ps_sqrt(int sq);
int		len_stack(t_node *stack);
int		get_min(t_node *stack);
int		node_distance(t_node *stack_a, t_node *stack_b, int index);
t_node	*get_last(t_node *stack, int direction);
bool	is_sorted(t_node *stack_a);

																//EXIT
void	my_exit(char *str, t_node *prev, t_node *next, int i);
void	word_number_check(int word_number, int *letter);
