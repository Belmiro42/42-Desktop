/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_Tokenise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 02:48:10 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/27 09:46:24 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void add_token(char *str, char ***tokens)
{
}

void token(char *str, char ***tokens, int *iterator, int *quotes)
{
	char *token;
	int change;

	while (str[*iterator])
	{
		change = in_quotes(str[*iterator], quotes);
		if (bels_isspace(str[*iterator]) != 0 || change == 1)
			iterator++;
		//else if (str[*iterator])
	}
}
int bels_isspace(char c)
{
	if (c == ' ' || (c < 14 && c > 8))
		return (1);
	return (0);
}

void io_operator(char *str, char ***tokens, int *iterator, int *last)
{
	if (str[*iterator] == '<')
	{
		if (str[*iterator + 1] == '<')
		{
			add_token(strdup("<<"), tokens);
			*iterator += 1;
		}
		else
			add_token(strdup("<"), tokens);
	}
	else if (str[*iterator] == '>')
	{
		if (str[*iterator + 1] == '>')
		{
			add_token(strdup(">>"), tokens);
			*iterator += 1;
		}
		else
			add_token(strdup(">"), tokens);
	}
	*iterator += 1;
}

void tokenise(t_pipe *pipe)
{
	char *str;
	char **tokens;
	int iterator;
	int last;
	int quotes;
	int change;

	last = 0;
	iterator = 0;
	str = pipe->raw_text;
	while (str[iterator])
	{
		change = in_quotes(str[iterator], &quotes);
		if (bels_isspace(str[iterator]) || change == 1)
			iterator++;
		else if ((str[iterator] == '<' || str[iterator] == '>') && quotes == 0)
			io_operator(str, &tokens, &iterator, &last);
		else
			token(str, &tokens, &iterator, &quotes);
	}
}