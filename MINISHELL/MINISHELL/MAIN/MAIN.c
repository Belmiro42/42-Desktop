/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:31:50 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/06 00:02:46 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//¡¡¡¡TODO: https://stackoverflow.com/questions/5412761/using-colors-with-printf

int main(int argc, char **argv, char **envp)
{
	char	*input;
	t_env	*environment;
	t_set	*set;

	signals();
	(void)argc;
	(void)argv;
	environment = create_env_variables(envp);
	while (true)
	{
		input = readline("temp prompt>");
		if (!input)
			break;
		if (input[0] != 0)
		{
			add_history(input);
			set = construct_parser_struct(input, environment);
			printf("%s\n", set->pipe->raw_text);
			free_parser_struct(set);
		}
		free(input);
	}
	free_env(environment);
	return(0);
}

/*int main(int argc, char **argv, char **envp)
{
	//char	*input;
	t_env	*environment;
	//t_set	*set;
	char	*tq = "export";
	char	*qe = "2hola";
	char	*qq = "YO=";
	char	*qr = NULL;
	char 	*txt[4] = {tq,qe, qq, qr};
	char 	*txt2[4] = {tq,qr, qe, qr};
	signals();
	(void)argc;
	(void)argv;
	environment = create_env_variables(envp);
	env_builtin(txt2, environment);
	tq = get_val_env("?", environment);
	printf("%s\n\nEXPORT BUILTIN HERE\n", tq);
	export_builtin(txt, environment);
	printf("\n\n");
	env_builtin(txt2, environment);
	free(tq);
	free_env(environment);
	return(0);
}*/