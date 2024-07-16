/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack_Init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:54:25 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/12 11:39:40 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_______CORE/Push_Swap.h"

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 	ATOI									│
//  ├───────────────────────────────────────────────────────────────────────┤
//	│ ATOI from Libft Project BUt DIFFERENT, errors called here no leaks.	|
//  └───────────────────────────────────────────────────────────────────────┘ 
static int	push_swap_atoi(char *str, t_node *stack)
{
	long	number;
	int		valence;

	valence = 1;
	number = 0;
	while (bels_isspace(*str))
		str++;
	if ((*str == '+' || (*str == '-' && valence-- && --valence)) && *str)
		str++;
	while ((48 <= *str && *str <= 57))
	{
		number = number * 10 + (*str++ - '0');
		if (number * valence < INT_MIN || number * valence > INT_MAX)
			my_exit("A VALUE IS BEYOND INT RANGE", stack, NULL, 1);
	}
	while (bels_isspace(*str))
		str++;
	if (*str || ((*(str - 1) == '-') || (*(str - 1) == '+')))
		my_exit("A VALUE IS NOT A NUMBER", stack, NULL, 1);
	return (number * valence);
}

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 MAKE NODES									│
//  └───────────────────────────────────────────────────────────────────────┘
static void	make_nodes(t_node **node, char **argv, int index)
{
	t_node	*current_node;
	int		valor;

	valor = push_swap_atoi(argv[index], *node);
	current_node = malloc(sizeof(t_node));
	if (!current_node)
		my_exit("MALLOC FAILED", *node, NULL, 1);
	current_node->value = valor;
	current_node->index = 0;
	current_node->prev = NULL;
	current_node->next = NULL;
	if (*node)
	{
		current_node->prev = *node;
		(*node)->next = current_node;
	}
	*node = current_node;
}

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │								STRJOIN									│
//  ├───────────────────────────────────────────────────────────────────────┤
//	│ Joins all parameters into a single string to split later				|
//  └───────────────────────────────────────────────────────────────────────┘
static char	*push_strjoin(char **argv, int *argc)
{
	static char	joined_str[70000];
	size_t		parameter_counter;
	size_t		joined_str_ind;
	size_t		char_ind;

	joined_str_ind = 0;
	parameter_counter = 0;
	while (parameter_counter != (size_t)(*argc) - 1)
	{
		char_ind = 0;
		while (argv[parameter_counter][char_ind])
		{
			joined_str[joined_str_ind++] = argv[parameter_counter][char_ind++];
			if (joined_str_ind > 60000)
				my_exit("TOO MANY PARAMETERS", NULL, NULL, 1);
		}
		joined_str[joined_str_ind++] = ' ';
		parameter_counter++;
	}
	joined_str[joined_str_ind] = '\0';
	*argc = parameter_counter;
	return (joined_str);
}

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							SPLIT FUNCTION								│
//  ├───────────────────────────────────────────────────────────────────────┤
//	│ Memory leaks are a plague, so to sidestep I made a static array.		|
//  └───────────────────────────────────────────────────────────────────────┘ 
static char	**split(char *str, char delimiter, int *word_count)
{
	static char	words[5000][14];
	static char	*result[5000];
	int			str_index;
	int			letter;
	int			word_number;

	str_index = -1;
	letter = 0;
	word_number = 0;
	while (str[++str_index] != '\0')
	{
		if (str[str_index] == delimiter && str[str_index - 1] != delimiter
			&& str_index != 0)
		{
			words[word_number][letter] = '\0';
			result[word_number] = words[word_number];
			word_number_check(word_number++, &letter);
		}
		else if (letter < 12)
			words[word_number][letter++] = str[str_index];
	}
	words[word_number][letter] = '\0';
	result[word_number] = words[word_number];
	*word_count = word_number;
	return (result);
}

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 MAKE STACK									│
//  ├───────────────────────────────────────────────────────────────────────┤
//	│ Having a split that returned a malloc would cause complications for	|
//	│ freeing malloc-ed data so we use a static that self frees upon program|
//	│ termination															|
//  └───────────────────────────────────────────────────────────────────────┘ 
t_node	*make_stack(int argc, char **argv)
{
	int		index;
	t_node	*current_node;
	t_node	*iterator;
	t_node	*return_node;

	arg_check(argv, argc - 1);
	argv = split(push_strjoin(argv, &argc), ' ', &index);
	current_node = NULL;
	while (index - 1 >= 0)
		make_nodes(&current_node, argv, --index);
	return_node = current_node;
	while (current_node)
	{
		iterator = current_node->prev;
		while (iterator)
		{
			if (iterator->value == current_node->value)
				my_exit("DUPLICATE VALUES", return_node, NULL, 1);
			iterator = iterator->prev;
		}
		current_node = current_node->prev;
	}
	return (return_node);
}
