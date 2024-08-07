/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:25:35 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/06 23:45:15 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	echo_builtin(char **args, t_env *environment)
{
	bool	flag;
	int		iterator;

	(void)environment;
	flag = false;
	iterator = 1;
	if (ft_strncmp(args[iterator], "-n", 3) == 0)
		flag = true;
	else
		ft_putstr_fd(args[iterator], 1);
	iterator++;
	while (args[iterator])
	{
		if (iterator > 2)
			ft_putstr_fd(" ", 1);
		else
			if (!flag)
				ft_putstr_fd(" ", 1);
		ft_putstr_fd(args[iterator++], 1);
	}
	if (!flag)
		ft_putstr_fd("\n", 1);
	return (EXIT_SUCCESS);
}
