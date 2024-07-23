/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_Variable_Expansion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 20:51:50 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/23 08:26:18 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ¡¡TODO: Protect Mallocs
// ¡¡TODO: APPEND WITH SINGLE QUOTES ENCLOSING
// ¡¡TODO: STRLEN STRCPY AND STRLCAT
// TODO: MAKE SURE WE HAVE A DUPLICATE OF VAL 


// FUNCTION DESCRIPTION: entre_comillas
// Whether we are in simple quotes or doubles quotes.
// 1 DENOTES WE ARE IN SIMPLE QUOTE
// 2 DENOTES WE ARE IN SIMPLE QUOTE
void entre_comillas(char c, int *quote)
{
	//printf("%c\t%d\n", c, *quote);											// DELETE Checker
	if (c == '\'' && *quote == 0)												// NOTE: 1 quire decir que estamos dentro de simples
		*quote = 1;
	else if (c == '\'' && *quote == 1)
		*quote = 0;
	if (c == '\"' && *quote == 0)												// NOTE: 1 quire decir que estamos dentro de dobles
		*quote = 2;
	else if (c == '\"' && *quote == 2)
		*quote = 0;
	//printf("%c\t%d\n", c, *quote);											// DELETE Checker
}

// FUNCTION DESCRIPTION: add character
// adds a character to a string
char	*add_character(char s1, char *s2, bool free1)
{
	char *ch;
	char *result;

	ch = malloc(sizeof(char) * 2);
	if (!ch)
		return NULL;
	ch[0] = s1;
	ch[1] = '\0';
	//printf("CH: %s\n", ch);													// DELETE Checker
	result = ft_strjoin(s2, ch, free1, 1);
	return result;
}


// FUNCTION DESCRIPTION: STR_JOIN
// joins two strings together
// frees aswell if you want it to
char	*ft_strjoin(char const *s1, char const *s2, bool free1, bool free2)
{
	char	*ptr;
	int		len;
	//printf("S1: %s \nS2: %s\n", s1, s2);										// DELETE Checker

	if (!s1 && !s2)
		return (NULL);
	if (s2 && !s1)
		return((char *)s2);
	if (s1 && !s2)
		return((char *)s1);
	len = strlen(s1) + strlen(s2);												// TODO: STRLEN STRCPY AND STRLCAT
	//printf("Len: %d\n", len);													// DELETE Checker
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	strlcpy(ptr, s1, len + 1);
	//printf("%s\n", ptr);														// DELETE Checker
	strlcat(ptr, s2, len + 1);
	//printf("%s\n", ptr);														// DELETE Checker
	if (free1 && s1)															// NOTE: Añadi este variable para liberar si quieres.
		free((char *)s1);
	if (free2 && s2)
		free((char *)s2);
	//printf("ptr: %s\n\n\n", ptr);												// DELETE Checker
	return (ptr);
}

// FUNCTION DESCRIPTION: get_var_value
// Find Var Name From String
// Get value from env
char	*get_var_value(int *iterator, char *input, int *quote)
{
	char	*var;
	char	*val;
	int		count;
	char	c;

	var = NULL;
	val = NULL;
	count = 0;
	(*iterator) ++;
	c = input[*iterator + count];
	while (count < 65 && (c == 95 || (47 < c && c < 58) || (64 < c && c < 92)
		|| (96 < c && c < 123)) && !(count == 0 && 47 < c && c < 58))
	{
		var = add_character(c, var, 1);
		count++;
		c = input[*iterator + count];
	}
	if (var)
	{
		val = getenv(var);														// NOTE: No liberar que esta apuntando al env no es un malloc
		if (val)
		{
			val = ft_strjoin(val, "\'", 0, 0);
			val = ft_strjoin( "\'", val, 0, 1);
		}
		free(var);
	}
	*iterator+=count - 1;
	return (val);
}

// FUNCTION DESCRIPTION: evaluate_var
// Find variables ($) and replace them with real values. Here we have an
// iterator to take us through the input of the command. Recursiveness is not
// necessary as when you add a variable within a variable it already expands out
// when assigning value
void evaluate_var(char *input, char **output, int *quote)
{
	int		iterator;
	char	*value;

	iterator = 0;
	while (input[iterator])
	{
		entre_comillas(input[iterator], quote);
		printf("%c\t%d\t%s\n", input[iterator], *quote, *output);				// DELETE Checker
		if (input[iterator] == '$' && *quote != 1 && input[iterator + 1]
			!= '\0' && input[iterator + 1] != ' ')
		{
			value = get_var_value(&iterator, input, quote);						// NOTE: DOES NOT ITERATE BEYOND SPECIAL CHARACTERS
			//printf("OUTPUT: %s\n", *output);									// DELETE Checker
			*output = ft_strjoin(*output, value, 1, 1); 						// TODO: APPEND WITH SINGLE QUOTES ENCLOSING
		}
		else
		{
			//printf("%c\n", input[iterator]); 									// DELETE Checker
			*output = add_character(input[iterator], *output, 1);				// NOTE: LITERALLY ADD THE CHARACTER TO THE STRING NOTE: IF NULL MAKE FIRST
		}
		iterator++;
	}
}
//FUNCTION DESCRIPTION: parsing primitive
char *parsing_primitive(char *input)
{
	int	quote;
	char	*output;

	quote = 0;
	output = NULL;
	evaluate_var(input, &output, &quote);
	return(output);
}

int main(int argc, char **argv)
{
	t_pipe_set *set;

	set = find_pipe_sets("$PATH|ello a || o");
	find_pipes_1(set);
	printf("%s\n", parsing_primitive(set->pipe->raw_text));
	return (0);
}


//ERROR w:
//"$2" -> should print nothing