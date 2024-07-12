/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _LIBERATION.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:40:12 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/12 22:51:47 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 LIBERATION									│
//  ├───────────────────────────────────────────────────────────────────────┤
static void phils_free(t_universal *global)
{
	int iterator;
	
	iterator = 0;
	while (iterator != global->phil_num + 1)
        free(global->philosophers[iterator++]);
    free(global->philosophers);	
}
static void strus_free(t_universal *global)
{	
	int iterator;

	iterator = 0;
	while (iterator != global->phil_num)
        free(global->structs[iterator++]);
    free(global->structs);
}
static void forks_free(t_universal *global)
{
	int iterator;
	
	iterator = 0;
	while (iterator != global->phil_num + 1)
        pthread_mutex_destroy(&global->forks[iterator++]);
    free(global->forks);
}
void my_exit(t_universal *global, int structs, int philosophers, int forks)
{
	if (forks != -1)
		forks_free(global);
	if (structs != -1)
		strus_free(global);
	if (philosophers != -1)
		phils_free(global);
	exit(EXIT_SUCCESS);
}	