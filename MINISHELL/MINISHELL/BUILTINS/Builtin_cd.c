/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:05:16 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/08 13:48:43 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	gotodir(t_env *environment, char *path)
{
	char *new_path;
	char *cwd;

	cwd = NULL;
	new_path = path;
	if (!access(new_path, R_OK | F_OK))
	{
		cwd = getcwd(cwd, 0);
		new_val_env("OLDPWD", cwd, &environment);
		free(cwd);
		cwd = NULL;
		chdir(new_path);
		cwd = getcwd(cwd, 0);
		new_val_env("PWD", cwd, &environment);
		free(cwd);
		return (EXIT_SUCCESS);
	}
	perror("cd: no such file or directory");
	return (EXIT_FAILURE);
}

static int	prv_dir(t_env *environment)
{
	char *prev_path;
	char *cwd;

	cwd = NULL;
	prev_path = get_val_env("OLDPWD", environment);
	if (!prev_path)
		perror("cd: OLDPWD not set");
	if (!prev_path)
			return (EXIT_FAILURE);
	if (!access(prev_path, R_OK | F_OK))
	{
		cwd = getcwd(cwd, 0);
		new_val_env("OLDPWD", cwd, &environment);
		free(cwd);
		cwd = NULL;
		chdir(prev_path);
		cwd = getcwd(cwd, 0);
		new_val_env("PWD", cwd, &environment);
		free(cwd);
		free(prev_path);
		return (EXIT_SUCCESS);
	}
	perror("cd: no such file or directory");
	return (EXIT_FAILURE);
}

static int	no_args(t_env *environment)
{
	char *home_path;
	char *cwd;

	cwd =  NULL;
	home_path = get_val_env("HOME", environment);
	if (!home_path)
			perror("cd: HOME not set");
	if (!home_path)
			return (EXIT_FAILURE);
	if (!access(home_path, R_OK | F_OK))
	{
		cwd = getcwd(cwd, 0);
		new_val_env("OLDPWD", cwd, &environment);
		free(cwd);
		cwd = NULL;
		chdir(home_path);
		cwd = getcwd(cwd, 0);
		new_val_env("PWD", cwd, &environment);
		free(cwd);
		free(home_path);
		return (EXIT_SUCCESS);
	}
	perror("cd: no such file or directory");
	return (EXIT_FAILURE);
}

int	cd_builtin(char **args, t_env *environment)
{
	if (ft_arrlen(args) > 2)
	{
		perror("cd: too many arguments");
		return (EXIT_FAILURE);
	}
	if (ft_arrlen(args) == 1)
	{
		if (no_args(environment))
			return(EXIT_SUCCESS);
		return(EXIT_FAILURE);
	}
	if (args[1][0] == '-' && !args[1][1])
	{
		if (prv_dir(environment))
			return(EXIT_SUCCESS);
		return(EXIT_FAILURE);
	}
	else
	{
		if (gotodir(environment, args[1]))
			return(EXIT_SUCCESS);
		return(EXIT_FAILURE);
	}
}