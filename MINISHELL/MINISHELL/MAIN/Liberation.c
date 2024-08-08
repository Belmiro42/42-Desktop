/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Liberation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:31:56 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/08 13:10:41 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// TODO: Can we make this work?
/*static void	magic_free(void *current_struct)
{
	t_input	*tmp;

	while (current_struct)
	{
		tmp = (t_input *)current_struct;
		current_struct = (void *)((t_input *)current_struct)->next;
		free(((t_input *)tmp)->filename);
		free(tmp);
	}
}*/

static void	free_input(t_input *current_struct)
{
	t_input	*tmp;

	while (current_struct)
	{
		tmp = current_struct;
		current_struct = (current_struct)->next;
		free(tmp->filename);
		free(tmp);
	}
}
static void	free_output(t_output *current_struct)
{
	t_output	*tmp;

	while (current_struct)
	{
		tmp = current_struct;
		current_struct = (current_struct)->next;
		free(tmp->filename);
		free(tmp);
	}
}


void	free_parser_struct(t_set *set, int *exit, t_env *environment)
{
	void		*tmp;
	t_pipe		*pipe;

	while ((unsigned long)set > (unsigned long)255)
	{
		pipe = set->pipe;
		while (pipe)
		{
			tmp = pipe->in;
			free_input((t_input *)tmp);
			tmp = pipe->out;
			free_output((t_output *)tmp);
			tmp = pipe;
			pipe = pipe->next;
			ft_freedbl(((t_pipe *)tmp)->args);
			free((((t_pipe *)tmp)->raw_text));
			free(tmp);
		}
		tmp = set;
		set = set->next;
		free(((t_set *)tmp)->raw_text);
		free((t_set *)tmp);
	}
	*exit = ft_atoi(environment->value);
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		env = env->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
}
