/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:02:21 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/04 02:05:35 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int env_builtin(t_env *env)
{
	t_env *cpy;
	while (cpy)
	{
		printf("%s=%s\n", cpy->key, cpy->value);
		cpy = cpy->next;
	}
}

// DESCRIPTION: SYNOPSIS
//	NOTE: I have a feeling man env is not the function we want ??
//env [OPTION]... [-] [NAME=VALUE]... [COMMAND [ARG]...]
//
// NOTE: env with no options or arguments