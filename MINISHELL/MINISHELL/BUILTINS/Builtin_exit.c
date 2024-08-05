/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:05:45 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/05 12:13:53 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*void exit_builtin(char **args, t_env *environment, t_set *original_first)
{
// TODO: TODO: UNTESTED
	if (ft_arrlen(args) > 2)
	{
		perror("TOO MANY ARGS");
	}
	else if ()
}*/

/*
DESCRIPTION: exit
The exit status shall be n, if specified, except that the behavior is
unspecified if n is not an unsigned decimal integer or is greater  than 255.
Otherwise, the value shall be the exit value of the last command executed, or
zero if no command was executed. When exit is executed in a trap action, the
last command is considered to be the command that executed immediately preceding
the trap action.The exit status shall be n, if specified, except that the
behavior is unspecified if n is not an unsigned decimal integer or is greater
than 255.  Otherwise, the value shall be the exit value of the last command
executed, or zero if no command was executed. When exit is executed in
a trap action, the last command is considered to be the command that executed
immediately preceding the trap action.
 
*/