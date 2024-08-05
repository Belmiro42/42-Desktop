/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:02:21 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/05 23:26:48 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// DESCRIPTION: SYNOPSIS
//env [OPTION]... [-] [NAME=VALUE]... [COMMAND [ARG]...]
//For minishell we want no arguments.
int	env_builtin(char **args, t_env *cpy)
{
	if (ft_arrlen(args) > 2)
	{
		perror("ENV: TOO MANY ARGUMENTS");
		return (1);
	}
	cpy = cpy->next;
	while (cpy)
	{
		ft_putstr_fd(cpy->key, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(cpy->value, 1);
		ft_putstr_fd("\n", 1);
		cpy = cpy->next;
	}
	return (0);
}
