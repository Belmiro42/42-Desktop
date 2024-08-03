/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_|_Split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 05:26:28 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/03 13:07:17 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// ¡¡TODO: PARSE ERROR


void pipe_to_back(t_pipe *current, t_pipe **head)
{
	t_pipe *cpy;

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

t_pipe *make_pipes(char **cpy, int *iterator)
{
	t_pipe *current;

	*iterator += 1;																//Skips the pipe symbol
	current = malloc(sizeof(t_pipe));											// TODO: MALLOC
	current->raw_text = *cpy;													// TODO: STRDUP
	current->in = NULL;
	current->out = NULL;
	current->args = malloc(sizeof(char *));
	(current->args)[0] = NULL;
	current->next = NULL;
	if (*cpy)
		*cpy = NULL;
	return(current);
}

void find_pipes(t_pipe_set *set)
{
	t_pipe *ret;
	int iterator;
	int value;
	char *cpy;
	int inquote;
	char *str;

	cpy = NULL;
	value = 0;
	inquote = 0;
	ret = NULL;
	iterator = -1;
	str = set->raw_text;
	while (str[++iterator])
	{
		//printf("%s\n", cpy);													// DELETE
		in_quotes(str[iterator], &inquote);
		//printf("CHAR = %c\tINT = %d\n", str[iterator], inquote);				// DELETE
		if (str[iterator] == '|' && inquote == 0)
			pipe_to_back(make_pipes(&cpy, &iterator), &ret);
		if ((iterator == 0 || str[iterator - 1] != '\0'))
			cpy = add_character(str[iterator], cpy, 1);
	}
	pipe_to_back(make_pipes(&cpy, &iterator), &ret);
	set->pipe = ret;
}