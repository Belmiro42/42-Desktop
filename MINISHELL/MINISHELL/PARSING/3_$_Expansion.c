/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_$_Expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:51:50 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/04 00:12:23 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// ¡¡TODO: Protect Mallocs
// ¡¡TODO: APPEND WITH SINGLE QUOTES ENCLOSING
// ¡¡TODO: STRLEN STRCPY AND STRLCAT
// TODO: MAKE SURE WE HAVE A DUPLICATE OF VAL



// FUNCTION DESCRIPTION: get_var_value
// Find Var Name From String
// Get value from env
char *get_var_value(int *iterator, char *input, int *quote)
{
	char *var;
	char *val;
	int count;
	char c;

	var = NULL;
	val = NULL;
	count = 0;
	(*iterator)++;
	c = input[*iterator + count];
	while (count < 65 && (c == '_' || ft_isdigit(c) || ft_isalpha(c) ))
	{
		var = add_character(c, var, 1);
		c = input[*iterator + ++count];
		printf("$$$$$$$$$$$$$$$$$\t%s\n", var);
	}
	if (var)
	{
		printf("$$$$$$$$$$$$$$$$$\t%s\n", var);
		val = ft_strdup(getenv(var));
		free(var);
		if (*quote == 0)
			val = ft_strjoin("\'", ft_strjoin(val, "\'", DEL, KEEP), KEEP, DEL);
	}
	*iterator += count - 1;
	return (val);
}

// FUNCTION DESCRIPTION: evaluate_var
// Find variables ($) and replace them with real values. Here we have an
// iterator to take us through the input of the command. Recursiveness is not
// necessary as when you add a variable within a variable it already expands out
// when assigning value
void evaluate_var(char *input, char **output, int *quote)
{
	int iterator;
	char *value;

	iterator = 0;
	while (input[iterator])
	{
		in_quotes(input[iterator], quote);
		// printf("%c\t%d\t%s\n", input[iterator], *quote, *output);			// DELETE Checker
		if (input[iterator] == '$' && *quote != 1 && input[iterator + 1] != '\0'
			&& (ft_isalpha(input[iterator + 1]) || input[iterator + 1] == 95))
		{
			value = get_var_value(&iterator, input, quote); 					// NOTE: DOES NOT ITERATE BEYOND SPECIAL CHARACTERS
			// printf("OUTPUT: %s\n", *output);									// DELETE Checker
			*output = ft_strjoin(*output, value, DEL, DEL); 						// TODO: APPEND WITH SINGLE QUOTES ENCLOSING
		}
		else
		{
			// printf("%c\n", input[iterator]); 								// DELETE Checker
			*output = add_character(input[iterator], *output, 1); 				// NOTE: LITERALLY ADD THE CHARACTER TO THE STRING NOTE: IF NULL MAKE FIRST
		}
		iterator++;
	}
}
// FUNCTION DESCRIPTION: parsing primitive
char *variable_expansion(char *input)
{
	int quote;
	char *output;

	quote = 0;
	output = NULL;
	evaluate_var(input, &output, &quote);
	free(input); 																// CONDITIONAL DELETE IDK
	return (output);
}

																				// TODO: only evaluates if $ is followed by a valid character _ or alph otherwise
																				// evlautes as '$'