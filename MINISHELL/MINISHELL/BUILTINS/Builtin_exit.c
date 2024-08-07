/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:05:45 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/07 15:29:56 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//NOTE: Exit status is the exit value of the last command or the second argument
// NOT SURE HOW TO EXIT THE EXECUTION

//NO PROBADO
static int get_num(char *str, t_env *environment)
{
	int index;

	index = 0;
	while (str[index])
	{
		if (index == 0 && str[index] == '-')
			index ++;
		if (!str[index] && !ft_isdigit(index))
		{
			perror("Needs numerical arguments you numpty");
			return (2);
		}
		index++;
	}
	free(environment->value);
	environment->value = ft_strdup(str);
	ºft_atoi(str);
}

int exit_builtin(char **args, t_env *environment)
{
	int exit_code;

	exit_code=0;
	if (ft_arrlen(args) > 1)
	{
		if (ft_arrlen(args) > 2)
			{
				perror("TOO MANY ARGUMENTS");
				exit_code = 1;
				return(exit_code);
			}
		exit_code = get_num(args[1], environment);
	}
	free(environment->next->value);
	environment->next->value = ft_strdup("1");
	return(ft_atoi(environment->value));
}

// Works but is a bit ugly. Exit triggers a trap signal. Maybe we can rework
// using the trap signal