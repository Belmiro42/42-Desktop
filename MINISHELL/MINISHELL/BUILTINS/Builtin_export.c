/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:28:00 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/05 23:11:09 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	export_error_check(char *str, int *exit_status)
{
	int iter;

	iter = 0;
	while (str[iter] != '=' && str[iter])
	{
		if ((iter == 0 && !(ft_isalpha(str[iter]) || str[iter] == '_')) ||
		!(ft_isalpha(str[iter]) || str[iter] == '_' || ft_isdigit(str[iter])))
			{
				*exit_status = 1;
				perror("String Not a Valid Identifier");
				return (1);
			}
		iter++;
	}
	return (0);
}

int	export_builtin(char **arg, t_env *environment)
{
	char	*key;
	char	*value;
	int		iter;
	int 	ret;

	iter = 0;
	ret = 0;
	while (arg[++iter] && ft_arrlen(arg) > 1)
	{
		if (!export_error_check(arg[iter], &ret) && ft_strnstr(arg[iter],
			"=", ft_strlen(arg[iter])))
		{
			key = ft_substr(arg[iter], 0, (int)((long)ft_strnstr(arg[iter],
			"=", ft_strlen(arg[iter])) -(long)arg[iter]));
			value = ft_substr(ft_strnstr(arg[iter],"=",
			ft_strlen(arg[iter])),  1,  ft_strlen(ft_strnstr(arg[iter],"=",
						ft_strlen(arg[iter])) + 1));
			new_val_env(key, value, environment);
			free(key);
			free(value);
		}
	}
	if (ft_arrlen(arg) == 1)
		env_builtin(arg, environment);
	return (ret);
}

// If any are wrong 