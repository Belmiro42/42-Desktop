/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_Transform_Input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:41:50 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/30 21:25:11 by bmatos-d         ###   ########.fr       */
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
			cpyp->raw_text = variable_expansion(cpyp->raw_text);
			//printf("%s\n", cpyp->raw_text); 									//   DELETE
			cpyp->raw_text = expand_wildcards(cpyp->raw_text);
			tokenise(cpyp, cpyp->raw_text);
			//Tokenise/ Complete Pipe Structs
			cpyp = cpyp->next;
		}
		set = set->next;
	}
	return (cpy);
}

int main()
{
	t_pipe_set *set;
	t_pipe_set *tmp_set;
	t_pipe *pipe;
	t_pipe *tmp;
	t_input *input;
	t_input *tmp_i;
	t_output *tmp_o;
	t_output *output;


	set = transform_input("find  >>*i*t* rm -rf");
	//set = transform_input("  j*  j*.c <j*.c \"as >>*.c < $USER \" $USER \" <<he\"r\'$USER\'e\"\" \'$USER\'doc ls -la >out > out2 | pipe2$QT_IM_MODULE && hola $USER ||  A j* <abc*'a*aa a'$USER*.c 6*.c \" *.c \"  \' *.c\' ");
	while (set != NULL)
	{
		printf("PIPE SET\n\n");
		printf("%d\t%s\n", set->exit_val, set->raw_text);
		pipe = set->pipe;
		while (pipe != NULL)
		{
			printf("\n\t\tPARSED\n");
			printf("\n\t\t%s\n", pipe->raw_text);
			input = pipe->in;
			while (input != NULL)
			{
				printf("\n\t\t\tINPUTS: %d\t%s\n", input->heredoc, input->filename);
				free(input->filename);
				tmp_i = input->next;
				free(input);
				input = tmp_i;
			}
			printf("\n");
			output = pipe->out;
			while (output != NULL)
			{
				printf("\n\t\t\tOUTPUT: %d\t%s\n", output->write, output->filename);
				free(output->filename);
				tmp_o = output->next;
				free(output);
				output = tmp_o;
			}
			int i = 0;
			printf("\n");
			while ((pipe->args)[i] != NULL)
			{
				printf("\n\t\t\tARGUMS: %d\t%s\n", i, (pipe->args)[i]);
				free((pipe->args)[i]);
				i++;
			}
			free((pipe->args));
			tmp = pipe->next;
			free(pipe);
			pipe = tmp;
		}
		tmp_set = set->next;
		free(set);
		set = tmp_set;
	}
	return (0);
}
