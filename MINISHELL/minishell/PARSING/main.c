/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 23:59:03 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/24 04:53:23 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv)
{
	t_pipe_set *set;

	// set = find_pipe_sets("mi nombre es $USER $PATH && $ | $PATH ||                            o");
	set = find_pipe_sets("\"\'s>\'\'\'\">\'\"\'");
	find_pipes_1(set);
	set->pipe->raw_text = parsing_primitive(set->pipe->raw_text);
	interpret_pipe(set->pipe);
	return (0);
}