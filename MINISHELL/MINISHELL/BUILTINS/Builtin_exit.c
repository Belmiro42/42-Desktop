/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:05:45 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/08 15:43:26 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//NOTE: Exit status is the exit value of the last command or the second argument
// NOT SURE HOW TO EXIT THE EXECUTION

//NO PROBADO
static int	get_num(char *str, t_env *environment)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (index == 0 && str[index] == '-')
			index ++;
		if (!str[index] && !ft_isdigit(index))
		{
			ft_putstr_fd("Minishell: exit: needs numerical arguments", 2);
			return (2);
		}
		index++;
	}
	free(environment->value);
	environment->value = ft_strdup(str);
	index = ft_atoi(str);
	while (index > 255 || index < 0)
		index %= 256;
	return (index);
}

int	exit_builtin(char **args, t_env *environment, t_set *set)
{
	int	exit_code;

	exit_code = 0;
	if (ft_arrlen(args) > 1)
	{
		if (ft_arrlen(args) > 2)
		{
			ft_putstr_fd("Minishell: exit: too many arguments", 2);
			exit_code = 1;
			return (exit_code);
		}
		exit_code = get_num(args[1], environment);
	}
	free_parser_struct(set, &set, environment);
	free_env(environment);
	ft_putstr_fd("LEFT IN EXIT", 1);
	exit(exit_code);
}

// Works but is a bit ugly.
// Exit triggers a trap signal. Maybe we can rework
// using the trap signal if shit