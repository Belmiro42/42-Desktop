/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:31:50 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/08 23:35:30 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//¡¡¡¡TODO: https://stackoverflow.com/questions/5412761/using-colors-with-printf

// LEGACY CODE -PRINT STRUCTURE
static void	print_sets(t_set *cpy)
{
	t_pipe		*pipe;
	t_input		*input;
	t_output	*output;
	char		**args;
	int			i;

	while (cpy)
	{
		printf("PIPESET %d %s\n", cpy->exit_val, cpy->raw_text);
		pipe = cpy->pipe;
		while (pipe)
		{
			printf("\tPIPE: %s\n", pipe->raw_text);
			input = pipe->in;
			while (input)
			{
				printf("\t\tIN:  %d\t%s\n", input->heredoc, input->filename);
				input = input->next;
			}
			output = pipe->out;
			printf("\n");
			while (output)
			{
				printf("\t\tOUT: %d\t%s\n", output->write, output->filename);
				output = output->next;
			}
			printf("\n");
			args = pipe->args;
			i = 0;
			while (args[i])
			{
				printf("\t\tARG: %d\t%s\n", i, args[i]);
				i++;
			}
			printf("\n");
			pipe = pipe->next;
		}
		cpy = cpy->next;
	}
}

void	process_input(char *input, t_set **set, t_env *environment, int *exit)
{
	if (input[0] != 0)
	{
		if (!parse_error(input, environment))
		{
			*set = construct_parser_struct(input, environment);
			print_sets(*set);
			//execucion aqui
			//execucion(set, environment);
			free_parser_struct(*set, exit, environment);
		}
		else
			*exit = 2;
	}
	add_history(input);
	free(input);
}

// DESCRIPTION: MAIN
int	main(int argc, char **argv, char **envp)
{
	char	*input;
	int		exit_code;
	t_env	*environment;
	t_set	*set;

	signals();
	set = NULL;
	environment = create_env_variables(envp, argc, argv);
	while (true)
	{
		input = readline("\x1B[37m\nWATCHU WAN> ");
		if (!input)
			break ;
		process_input(input, &set, environment, &exit_code);
	}
	free_env(environment);
	return (exit_code);
}

//  LEGACY CODE - EXPORT TEST
/*int main(int argc, char **argv, char **envp)
{
	//char	*input;
	t_env	*environment;
	//t_set	*set;
	char	*tq = "echo";
	char	*qe = "-n";
	char	*qq = "x";
	char	*qu = "y";
	char	*qr = NULL;
	char 	*txt[5] = {tq,qe, qq, qu, qr};
	char 	*txt2[5] = {tq,qr, qe, qr};
	signals();
	(void)argc;
	(void)argv;
	environment = create_env_variables(envp);
	env_builtin(txt2, environment);
	printf("\n\n");
	tq = get_val_env("?", environment);
	printf("%s\n\nEXPORT BUILTIN HERE\n", tq);
	export_builtin(txt, environment);
	printf("\n\n");
	env_builtin(txt2, environment);
	free(tq);
	free_env(environment);
	return(0);
}*/

// LEGACY CODE - UNSET TEST
/*int main(int argc, char **argv, char **envp)
{
	t_env	*environment;
	char	*tq = "unset";
	char	*qe = "USER";
	char	*qu = "cat -e";
	char	*qr = NULL;
	char 	*txt[5] = {tq,qe, qr, qu, qr};
	(void)argc;
	(void)argv;
	environment = create_env_variables(envp);
	printf("Echo\n");


	tq = get_val_env("USER", environment);
	printf("%s\n", tq);
	free(tq);


	unset_builtin(txt, environment);

	tq = get_val_env("USER", environment);
	printf("%s\n", tq);

	free_env(environment);
	return(0);
}*/

// LEGACY CODE - ECHO TEST
/*int main(int argc, char **argv, char **envp)
{
	//char	*input;
	t_env	*environment;
	//t_set	*set;
	char	*tq = "echo";
	char	*qe = "2Hola=5";
	//char	*qq = "|";
	char	*qu = "cat -e";
	char	*qr = NULL;
	char 	*txt[5] = {tq,qe, qr, qu, qr};
	char 	*txt2[5] = {tq,qr, qe, qr};
	signals();
	(void)argc;
	(void)argv;
	environment = create_env_variables(envp);
	//env_builtin(txt2, environment);
	//printf("\n\n");
	//tq = get_val_env("?", environment);
	printf("Echo\n");
	echo_builtin(txt, environment);
	tq = get_val_env("?", environment);
	printf("%s\n", tq);
	free(tq);
	new_val_env("USE", "4", &environment);
	export_builtin(txt, environment);
	tq = get_val_env("?", environment);
	printf("%s\n", tq);
	free(tq);
	env_builtin(txt2, environment);
	//export_builtin(txt, environment);
	//printf("\n\n");
	//env_builtin(txt2, environment);
	//free(tq);
	free_env(environment);
	return(0);
}*/

// LEGACY CODE - EXIT TEST
/*int main(int argc, char **argv, char **envp)
{
	//char	*input;
	t_env	*environment;
	//t_set	*set;
	char	*tq = "exit";
	char	*qe = "5";
	char	*qu = "7";
	char	*qr = NULL;
	char 	*txt[5] = {tq,qe, qu, qr, qr};
	(void)argc;
	(void)argv;
	environment = create_env_variables(envp);
	printf("EXIT\n");
	exit_builtin(txt, environment);
	tq = get_val_env("?", environment);
	printf("%s\n", tq);
	free(tq);
	tq = (char *)((unsigned long)ft_atoi(environment->value));
	free_env(environment);
	return((unsigned long)tq);
}*/

// LEGACY CODE - PWD TEST
/*int main(int argc, char **argv, char **envp)
{
	//char	*input;
	t_env	*environment;
	//t_set	*set;
	char	*tq = "exit";
	char	*qe = "5";
	char	*qu = "7";
	char	*qr = NULL;
	char 	*txt[5] = {tq,qr, qu, qe, qr};

	environment = create_env_variables(envp, argc, argv);
	pwd_builtin(txt, environment);
	free_env(environment);
	return((unsigned long)tq);
}*/

// LEGACY CODE - CD TEST
/*int main(int argc, char **argv, char **envp)
{
	//char	*input;
	t_env	*environment;
	//t_set	*set;
	char	*tq = "exit";
	char	*qe = "-";
	char	*qu = "7";
	char	*qr = NULL;
	char 	*txt[5] = {tq, qe, qr, qe, qr};
	char 	*tx2[5] = {tq, qr, qu, qe, qr};

	environment = create_env_variables(envp, argc, argv);
	pwd_builtin(tx2, environment);
	cd_builtin(txt, environment);
	pwd_builtin(tx2, environment);
	free_env(environment);
	return((unsigned long)tq);
}*/
