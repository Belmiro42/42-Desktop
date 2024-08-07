/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:05:02 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/06 20:17:55 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	pwd_builtin(char **arg, t_env *environment)
{
	char	*pwd;

	if (arr_len(arg) > 1)
	{
		perror("pwd: too many arguments");
		return ((EXIT_FAILURE));
	}
	pwd = get_val_env("PWD", environment);
	ft_putstr_fd(pwd, 1);
	free(pwd);
	return (EXIT_SUCCESS);
}

/*
DESCRIPTION: SYNOPSIS
pwd [OPTION]...

NOTE: In our case
pwd

use $PWD but need to manage symlinks. If no option is specified, -P is assumed.
-P, --physical avoid all symlinks

*/
