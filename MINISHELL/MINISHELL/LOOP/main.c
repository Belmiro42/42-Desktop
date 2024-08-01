/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:31:56 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/01 13:29:01 by bmatos-d         ###   ########.fr       */
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
	char 	prompt[3][80] = {{"   Yᵒᵘ Oᶰˡʸ Lᶤᵛᵉ Oᶰᶜᵉ  >"},{"     (ノಠ益ಠ)ノ彡┻━┻   >"},{ "  ヽ༼ ຈل͜ຈ༼ ▀̿̿Ĺ̯̿̿▀̿ ̿༽Ɵ͆ل͜Ɵ͆ ༽ﾉ >"}};
	minishell_env = *(create_env_variables(envp));
	i = 0;
	while (true)
	{
		printf("%s\n", get_val_env("PWD"));
		input = readline(prompt[i]);
		add_history(input);
		print_pipes(transform_input(ft_strjoin("  ", input, KEEP, DEL)));
		free(input);
		i =  (i+1) % 3;
	}
}