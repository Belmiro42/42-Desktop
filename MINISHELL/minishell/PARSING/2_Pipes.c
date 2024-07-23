/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_Pipes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 05:26:28 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/23 08:26:12 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

	*iterator += 1;
	//printf("1STR; %s\n", *cpy);												// DELETE
	current = malloc(sizeof(t_pipe));											// TODO: MALLOC
	current->raw_text = *cpy;													// TODO: STRDUP
	current->in = NULL;
	current->out = NULL;
	current->arguments = NULL;
	current->next = NULL;
	//printf("2STR; %s\n", current->raw_text);									// DELETE
	if (*cpy)
		*cpy = NULL;
	return(current);
}

t_pipe *find_pipes_2(char *str)
{
	t_pipe *ret;
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
		if (str[iterator] == '|' && inquote == 0)
			pipe_to_back(make_pipes(&cpy, &iterator), &ret);
		if ((str[iterator - 1] != '\0' || iterator == 0))
			cpy = add_character(str[iterator], cpy, 1);
		iterator++;
	}
	//if (iterator == strlen(str))												// TODO: PARSE ERROR
	pipe_to_back(make_pipes(&cpy, &iterator), &ret);
	return (ret);
}

void	find_pipes_1(t_pipe_set *set)
{
	set->pipe = find_pipes_2(set->raw_text);
	free(set->raw_text);
}
