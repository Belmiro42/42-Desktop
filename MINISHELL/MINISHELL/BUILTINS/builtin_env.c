/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:02:21 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/31 08:52:21 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 // NOTE: env with no options or arguments

int env_builtin()
{
	env = our environment
	while(env)
	{
		printf("%s=%s\n", KEY, VALUE);
		env = env->next;
	}
}
 /*
 DESCRIPTION: SYNOPSIS
	NOTE: I have a feeling man env is not the function we want ??
env [OPTION]... [-] [NAME=VALUE]... [COMMAND [ARG]...]
 */

//https://github.com/MasterCodeMFE/minitalk
