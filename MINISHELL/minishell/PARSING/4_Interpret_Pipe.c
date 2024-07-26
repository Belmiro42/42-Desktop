/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_Interpret_Pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 00:10:41 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/24 22:33:28 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void interpret_pipe(t_pipe *p)
{
	int iterator;
	int in_quote;
	int cmp;

	iterator = 0;
	in_quote = 0;
	printf("%s\n", p->raw_text); // DELETE
	while (p->raw_text[iterator])
	{
		if (p->raw_text[iterator] == '\'' || p->raw_text[iterator] == '\"')
		{
			cmp = in_quote;
			in_quotes(p->raw_text[iterator], &in_quote);
			if (cmp == in_quote)
				printf("%c\n", p->raw_text[iterator]);
		}
		else
		{
			if ((p->raw_text[iterator] == '<' | p->raw_text[iterator] == '>') && in_quote == 0)
				printf("\n");
			printf("%c\n", p->raw_text[iterator]);
		}
		iterator++;
	}
}