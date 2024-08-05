/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:04:08 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/05 16:46:41 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	unset_builtin(char **arg, t_env *env)
{
// TODO: TODO: UNTESTED
	int	iterator;

	iterator = 1;
	while (arg[iterator])
	{
		del_var_env(arg[iterator], &env);
		iterator++;
	}
	return (0);
}

/*
DESCRIPTION:
unset [-fv] name...

NOTE: In our case
unset name

Unsetting a variable or function that was not previously set shall not be
considered an error and does not cause the shell to abort.

*/