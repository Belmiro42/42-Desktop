/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_Tokenise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:45:14 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/04 16:18:12 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *get_token(char *str, int *iterator)
{
	char	*token;
	int		quote;
	int		change;

	quote = 0;
	token = ft_strdup("");
	while (ft_isspace(str[*iterator]))
		(*iterator)++;
	while (((str[*iterator] && str[*iterator] != '<' && str[*iterator] != '>') || quote != 0) && *iterator <= (int)strlen(str))
	{
		if (ft_isspace(str[*iterator]) && quote == 0)
			break;
		change = in_quotes(str[*iterator], &quote);
		if (change != 1)
			token = add_character(str[*iterator], token, 1);
		(*iterator)++;
	}
	if (strlen(token) == 0)
		return (free(token), NULL);
	return (token);
}

void make_out(t_pipe *current, bool param, char **filename)
{
	t_output		*cpy;
	t_output		*f_current;

	f_current = malloc(sizeof(t_output));
	f_current->write = param;
	//printf("FILENAME\t%s\n", *filename);
	f_current->filename = *filename;
	f_current->filename = strdup(*filename);
	//printf("FILENAME: %s\tBOOL\t%d\n", *filename, param);
	free(*filename);
	*filename = NULL;
	f_current->next = NULL;
	if (current->out)
	{
		cpy = current->out;
		while (cpy->next)
			cpy = cpy->next;
		cpy->next = f_current;
	}
	else
		current->out = f_current;
}
void make_in(t_pipe *current, bool param, char **filename)
{
	t_input		*cpy;
	t_input		*f_current;

	f_current = malloc(sizeof(t_input));
	f_current->heredoc = param;
	f_current->filename = strdup(*filename);
	//printf("FILENAME: %s\tBOOL\t%d\n", *filename, param);
	free(*filename);
	*filename = NULL;
	f_current->next = NULL;
	if (current->in)
	{
		cpy = current->in;
		while (cpy->next)
			cpy = cpy->next;
		cpy->next = f_current;
	}
	else
		current->in = f_current;
}

void trigger_io(t_pipe *current, char *str, int *iterator, bool param)
{
	char	*filename;

	if (str[*iterator] == '>')
	{
		(*iterator)++;
		if (str[*iterator] == '>')
		{
			(*iterator)++;
			param = false;
		}
		filename = get_token(str, iterator);
		make_out(current, param, &filename);
	}
	else if (str[*iterator] == '<')
	{
		(*iterator)++;
		if (str[*iterator] == '<')
			(*iterator)++;
		else if (str[*iterator] == '>')
			(*iterator)++;
		else
			param = false;
		filename = get_token(str, iterator);
		make_in(current, param, &filename);
	}
}

void add_to_args(char ***arr, char *token)
{
	int count;
	int iterator;
	char **narr;

	count = 0;
	iterator = 0;
	while ((*arr)[count])
		count++;
	narr = malloc(sizeof(char *) * (count + 2));
	while (iterator != count)
	{
		narr[iterator] = (*arr)[iterator];
		iterator++;
	}
	narr[iterator] = token;
	narr[iterator + 1] = NULL;
	free(*arr);
	(*arr) = narr;
}

void tokenise(t_pipe *current, char *str)
{
	int		iterator;
	int		quote;
	int		change;

	iterator = 0;
	while (iterator < (int)strlen(str))
	{
		change = in_quotes(str[iterator], &quote);
		while (ft_isspace(str[iterator]))
			iterator++;
		if (str[iterator] == '<' || str[iterator] == '>')
			trigger_io(current, str, &iterator, true);
		else
			add_to_args(&(current->args), get_token(str, &iterator));
	}
}