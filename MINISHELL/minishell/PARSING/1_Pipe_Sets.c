/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_Pipe_Sets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 05:35:59 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/23 07:40:19 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// ¡¡TODO: STRDUP
// ¡¡TODO: MALLOC
// ¡¡TODO: PARSE ERROR
// ¡¡TODO: INQUOTES

// FUNCTION DESCRIPTION: add_to_back
// Adds the current node to the back of the list
void add_to_back(t_pipe_set *current, t_pipe_set **head)
{
	t_pipe_set *cpy;

	cpy = *head;
	if (*head == NULL)
	{
		*head = current;
		return;
	}
	while (cpy->next)
		cpy = cpy->next;
	cpy->next = current;
}

t_pipe_set *make_pipe_sets(char **cpy, int *value, int *iterator, char *str)
{
	t_pipe_set *current;
	*iterator += 2;

	//printf("STR; %s\n", *cpy);												// DELETE
	//printf("EXIT; %d\n", *value);												// DELETE
	//printf("CHAR; %c\n", str[*iterator - 1] );								// DELETE

	current = malloc(sizeof(t_pipe_set));										// TODO: MALLOC
	current->raw_text = *cpy;													// TODO: STRDUP
	current->exit_val = *value;
	current->next = NULL;
	current->pipe = NULL; 
	//printf("IN FUNC -s\t %s\n", current->raw_text);							// DELETE
	//printf("IN FUNC -d\t %d\n", current->exit_val);							// DELETE
	if (*str && str[*iterator - 1] == '|')
		*value = 1;
	else
		*value = 2;
	if (*cpy)
		*cpy = NULL;
	return(current);
}

t_pipe_set *find_pipe_sets(char *str)
{
	t_pipe_set *ret;
	int iterator;
	int value;
	char *cpy;
	int inquote;

	cpy = NULL;
	value = 0;
	inquote = 0;
	ret = NULL;
	iterator = 0;


	while (str[iterator])
	{
		//printf("%s\n", cpy);													// DELETE
		if ((str[iterator] == '|' && str[iterator + 1] == '|')
			|| (str[iterator] == '&' && str[iterator + 1] == '&'))
			add_to_back(make_pipe_sets(&cpy, &value, &iterator, str), &ret);
			//add_to_back(make_pipe_sets(&str, &value, &iterator), &ret);
		//printf("%c\n", str[iterator]);										// DELETE
		//printf("who %s\n", str + iterator - 1);								// DELETE
		//printf("%c\n", str[iterator]);										// DELETE
		if ((str[iterator - 1] != '\0' || iterator == 0))
			cpy = add_character(str[iterator], cpy, 1);
		iterator++;
	}
	//if (iterator == strlen(str))												// TODO: PARSE ERROR
	add_to_back(make_pipe_sets(&cpy, &value, &iterator, str), &ret);
	return (ret);
}
