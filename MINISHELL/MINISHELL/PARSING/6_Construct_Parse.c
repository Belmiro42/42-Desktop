/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_Construct_Parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 21:41:50 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/06 00:09:37 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_set *construct_parser_struct(char *input, t_env *environment)
{
	t_pipe		*pipe;
	t_set		*set;
	t_set		*set_cpy;

	set = find_sets(input);
	set_cpy = set;
	while (set_cpy != NULL)
	{
		find_pipes(set_cpy);
		pipe = set_cpy->pipe;
		while (pipe != NULL)
		{
			pipe->raw_text = variable_expansion(pipe->raw_text, environment);
			pipe->raw_text = expand_wildcards(pipe->raw_text);
			tokenise(pipe, pipe->raw_text);
			pipe = pipe->next;
		}
		set_cpy = set_cpy->next;
	}
	return (set);
}