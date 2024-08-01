/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Signal_Handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:50:52 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/01 18:50:54 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void handler1()
{
	rl_on_new_line();
	rl_replace_line("", 0);
}

void handler2()
{
	printf("\n Ctrl-\\ \n");
}

void signals()
{
	signal(SIGINT, handler1);
	signal(SIGQUIT, handler2);
}