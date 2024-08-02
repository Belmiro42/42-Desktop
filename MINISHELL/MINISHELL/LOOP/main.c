/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:31:56 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/02 13:28:23 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../minishell.h"


// TODO: MAYBE DO A PWD SCRIPT
/*char *get_prompt()
{
	char *text;
	int fs;

	text = get_val_env("PWD");
	while (strlen(text) > 30)
		text = ft_strnstr(text + 1, "/", ft_strlen(text));
	text = ft_strdup
	fs = ft_strlen(text);
	while (fs++ < 30)
		ft_strjoin(".", text, KEEP, DEL);
}*/

int main(int argc, char **argv, char **envp)
{
	char *input;
	int		fs;
	int 	i;
	char 	prompt[3][100] = {{"\x1B[31m╚   Yᵒᵘ Oᶰˡʸ Lᶤᵛᵉ Oᶰᶜᵉ  >\x1B[32m"},{"\x1B[31m╚     (ノಠ益ಠ)ノ彡┻━┻   >\x1B[32m"},{ "\x1B[31m╚  ヽ༼ ຈل͜ຈ༼ ▀̿̿Ĺ̯̿̿▀̿ ̿༽Ɵ͆ل͜Ɵ͆ ༽ﾉ >\x1B[32m"}};
	minishell_env = create_env_variables(envp);
	i = 0;
	signals();
	while (true)
	{
		printf("%s╔%s\n", KRED, get_val_env("PWD"));
		input = readline(prompt[i]);
		if (!input)
			break;
		add_history(input);
		print_pipes(transform_input(input));
		i =  (i+1) % 3;
	}
	//cleanup here;*
}