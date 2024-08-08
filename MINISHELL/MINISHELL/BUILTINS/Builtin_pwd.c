/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:05:02 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/08 00:31:15 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	pwd_builtin(char **arg, t_env *environment)
{
	char	*pwd;

	(void)environment;
	(void)arg;
	pwd = NULL;
	pwd = getcwd(pwd, 0);
	ft_putstr_fd(pwd, 1);
	ft_putstr_fd("\n", 1);
	free(pwd);
	free(environment->value);
	environment->value = ft_strdup("0");
	return (ft_atoi(environment->value));
}
