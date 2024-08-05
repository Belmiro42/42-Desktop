/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Liberation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:31:56 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/05 12:20:03 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	magic_free(void *current_struct)
{
	t_input	*tmp;

	while (current_struct)
	{
		tmp = (t_input *)current_struct;
		current_struct = (void *)((t_input *)current_struct)->next;
		free(((t_input *)tmp)->filename);
		free(tmp);
	}
}

void	free_parser_struct(t_set *set)
{
	void		*tmp;
	t_pipe		*pipe;
	t_input		*input;
	t_output	*output;

	while (set)
	{
		pipe = set->pipe;
		while (pipe)
		{
			input = pipe->in;
			magic_free(input);
			output = pipe->out;
			magic_free(output);
			tmp = pipe;
			pipe = pipe->next;
			ft_freedbl(((t_pipe *)tmp)->args);
			free((((t_pipe *)tmp)->raw_text));
			free(tmp);
		}
		tmp = (void *)set;
		set = set->next;
		free(((t_set *)tmp)->raw_text);
		free((t_set *)tmp);
	}
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

void	my_exit(t_env *env, t_set *set)
{
	free_env(env);
	free_parser_struct(set);
}
