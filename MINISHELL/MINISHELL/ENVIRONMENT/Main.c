/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 07:35:00 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/01 08:39:03 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_env *environment;

	minishell_env = *(create_env_variables(envp));
	if (key_exists_env("USER"))
	{
		printf("Checks Out\n");
		printf("Value is\t%s\n", get_val_env("USER"));
		change_val_env("USER", "JON SNOW");
		printf("New Value is\t%s\n", get_val_env("USER"));
		add_key_env("WTF", "YES");
		printf("Value is\t%s\n", get_val_env("WTF"));

	}
/*	extern(environment);
	printf("%s", get_env(argv[1]));*/
}