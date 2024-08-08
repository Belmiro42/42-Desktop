/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Signal_Handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:50:52 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/07 17:32:46 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	handle_signals(int sigval)
{
	if (sigval == SIGINT)
	{
		//PADRE
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		// COMPORTAMIENTO DISTINTO PARA HIJO -> VEREMOS
	}
}
void	signals(void)
{
	struct sigaction	new_line;
	struct sigaction	ignore;

	new_line.sa_handler = &handle_signals;
	sigaction(SIGINT, &new_line, NULL);
	sigemptyset(&new_line.sa_mask);
    new_line.sa_flags = 0;

	ignore.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &ignore, NULL);
	sigemptyset(&ignore.sa_mask);
    ignore.sa_flags = 0;
}
/*SIGNALS
	signal
	sigaction
	sigemptyset
	sigaddset*/