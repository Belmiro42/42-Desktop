/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:05:45 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/04 16:40:01 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// NOTE: exit with no options
void exit_builtin(env )
{
	//free all my stuff
	if (!n)
		n = "last command exit status"											
	exit(n)
}

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