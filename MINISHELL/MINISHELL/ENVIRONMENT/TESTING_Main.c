/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TESTING_Main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 07:35:00 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/02 15:19:58 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*int main(int argc, char **argv, char **envp)
{
	t_env *environment;
	t_env *cpy;
	t_env *tmp;

	minishell_env = create_env_variables(envp);								//Single leak in create env
	if (key_exists_env("USER"))
	{
		printf("Checks Out\n");
		printf("Value is\t%s\n", get_val_env("USER"));
		new_val_env("USER", "JON SNOW");										//single leak here
		printf("New Value is\t%s\n", get_val_env("USER"));
		new_val_env("WTF", "YES");
		printf("Value is\t%s\n", get_val_env("WTF"));
	}
	cpy = minishell_env;
	while (cpy)																	//Invalid Frees?
	{
		tmp = cpy->next;
		free(cpy->key);
		free(cpy->value);
		free(cpy);
		cpy = tmp;
	}
}*/