/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_Transform_Input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:41:50 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/27 10:18:50 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_pipe_set *transform_input(char *input)
{
	t_pipe_set *set;
	t_pipe_set *cpy;
	t_pipe *cpyp;

	set = find_pipe_sets(input);
	cpy = set;
	while (set != NULL)
	{
		find_pipes_1(set);
		cpyp = set->pipe;
		while (cpyp != NULL)
		{
			cpyp->raw_text = parsing_primitive(cpyp->raw_text);
			cpyp = cpyp->next;
		}
		set = set->next;
	}
	return (cpy);
}

int main()
{
	t_pipe_set *set;
	t_pipe *pipe;
	t_input *input;
	t_output *output;

	set = transform_input("< \" $USER \" << he\"r\'\'e\"doc ls -la >out > out2 | pipe2$QT_IM_MODULE ||hola");
	while (set != NULL)
	{
		printf("%s\n", set->raw_text);
		pipe = set->pipe;
		while (pipe != NULL)
		{
			printf("\n\t%s\n", pipe->raw_text);
			input = pipe->in;
			while (input != NULL)
			{
				printf("\n\t\tINPUTS: %d\t%s\n", input->heredoc, input->filename);
				input = input->next;
			}
			output = pipe->out;
			while (output != NULL)
			{
				printf("\n\t\tOUTPUTS: %s\t%d\n", output->name, output->write);
				output = output->next;
			}
			pipe = pipe->next;
		}
		set = set->next;
	}
	return (0);
}
