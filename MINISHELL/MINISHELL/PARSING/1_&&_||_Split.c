/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_&&_||_Split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 05:35:59 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/05 16:19:57 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// ¡¡TODO: MALLOC
// ¡¡TODO: PARSE ERROR

// FUNCTION DESCRIPTION: add_to_back
// Adds the current node to the back of the list
void add_to_back(t_set *current, t_set **head)
{
	t_set *cpy;

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

t_set *make_sets(char **cpy, int *value, int *iterator, char *str)
{
	t_set *current;

	// NOTE: Comprobamos que no estemos al final del input
	// NOTE: Anadimos dor para saltar de '|| asd' hasta '|| asd'
	// NOTE:							  ^                ^
	if (*iterator < (int)ft_strlen(str))
		*iterator += 2;
	current = malloc(sizeof(t_set));
	current->raw_text = *cpy;
	current->exit_val = *value;
	current->next = NULL;
	current->pipe = NULL;
	if (*str && str[*iterator - 1] == '|')
		*value = 1;
	else
		*value = 2;
	if (*cpy)
		*cpy = NULL;
	return(current);
}

t_set *find_sets(char *str)
{
	t_set *ret;
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
		in_quotes(str[iterator], &inquote);
		if ((inquote == 0 && (str[iterator] == '|') && str[iterator + 1] == '|')
			|| (str[iterator] == '&' && str[iterator + 1] == '&'))
			add_to_back(make_sets(&cpy, &value, &iterator, str), &ret);
		if ((iterator == 0 || str[iterator - 1] != '\0'))
			cpy = add_character(str[iterator], cpy, 1);
		iterator++;
	}
	add_to_back(make_sets(&cpy, &value, &iterator, str), &ret);
	return (ret);
}
