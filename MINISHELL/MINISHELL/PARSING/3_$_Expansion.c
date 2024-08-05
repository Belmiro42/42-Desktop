/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_$_Expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:51:50 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/05 23:56:04 by bmatos-d         ###   ########.fr       */
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
char *get_var_value(int *iterator, char *input, int *quote, t_env *environment)
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
	while (count < 65 && (c == '_' || ft_isalnum(c)))
	{
		var = add_character(c, var, 1);
		c = input[*iterator + ++count];
	}
	printf("VAR:\t %s\n", var);
	if (var)
	{
		val = ft_strdup(getenv(var));
		free(var);
		printf("VAL\t%s\n", val);
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
void evaluate_var(char *input, char **output, int *quote, t_env *env)
{
	int iter;
	char *value;

	iter = 0;
	while (input[iter])
	{
		in_quotes(input[iter], quote);
		if ((input[iter] == '$' && input[iter + 1] == '?'))
		{
			*output = ft_strjoin(*output, get_val_env("?", env), DEL, DEL);
			iter += 2;
		}
		else if ((input[iter] == '$' && *quote != 1 && input[iter + 1] != '\0'
			&& (ft_isalpha(input[iter + 1]) || input[iter + 1] == 95)))
		{
			value = get_var_value(&iter, input, quote, env); 					// NOTE: DOES NOT ITERATE BEYOND SPECIAL CHARACTERS
			*output = ft_strjoin(*output, value, DEL, DEL);
		}
		else
		{
			*output = add_character(input[iter], *output, 1); 					// NOTE: LITERALLY ADD THE CHARACTER TO THE STRING NOTE: IF NULL MAKE FIRST
		}
		iter++;
	}
}
// FUNCTION DESCRIPTION: parsing primitive
char *variable_expansion(char *input, t_env *environment)
{
	int quote;
	char *output;

	quote = 0;
	output = NULL;
	evaluate_var(input, &output, &quote, environment);
	free(input);
	return (output);
}
