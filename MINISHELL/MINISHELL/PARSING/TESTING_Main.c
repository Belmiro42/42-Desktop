/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TESTING_Main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:41:50 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/04 00:14:57 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void transform_input(char *input)
{
	t_pipe *pipe;
	t_pipe_set *set;
	t_input *temp_in;
	t_pipe *temp_pipe;
	t_output *temp_out;
	t_pipe_set *temp_set;
	char **args_cpy;
	int iterator;

	set = find_pipe_sets(input);
	while (set != NULL)
	{
		printf("SET RAW TXT:\t%s\n", set->raw_text);
		find_pipes(set);
		pipe = set->pipe;
		while (pipe != NULL)
		{
			temp_pipe = pipe;
			printf("\tPIP RAW TXT:\t%s\n", pipe->raw_text);
			pipe->raw_text = variable_expansion(pipe->raw_text);
			printf("\n\tVAR EXP TXT:\t%s\n", pipe->raw_text);
			pipe->raw_text = expand_wildcards(pipe->raw_text);
			printf("\n\tWDC EXP TXT:\t%s\n", pipe->raw_text);
			tokenise(pipe, pipe->raw_text);
			iterator = 0;

			while (pipe->args[iterator])
			{
				printf("\n\t\tARG %s\n", pipe->args[iterator]);
				free(pipe->args[iterator++]);
			}

			while (pipe->in)
			{
				temp_in = pipe->in;
				printf("\n\t\tIN %s\n", pipe->in->filename);
				pipe->in = pipe->in->next;
				free(temp_in->filename);
				free(temp_in);
			}
			while (pipe->out)
			{
				temp_out = pipe->out;
				printf("\n\t\tout %s\n", pipe->out->filename);
				pipe->out = pipe->out->next;
				free(temp_out->filename);
				free(temp_out);
			}
			pipe = pipe->next;
			free(temp_pipe->raw_text);
			free(temp_pipe->args);
			free(temp_pipe);
		}
		temp_set = set;
		set = set->next;
		free(temp_set->raw_text);
		free(temp_set);
	}
}

int main(int argc, char **argv)
{
	transform_input("asd$a$USER");
}
