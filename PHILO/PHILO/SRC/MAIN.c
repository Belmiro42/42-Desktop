/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:16:01 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/16 06:10:32 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	main(int argc, char **argv)
{
	t_universal	global;

	pthread_mutex_init(&global.end_mutex, NULL);
	global.forks = NULL;
	global.philosophers = NULL;
	global.structs = NULL;
	argv = phil_split(join_all_inputs(&argv), ' ', &argc);
	initialise_struct(&global, argv);
	create_threads(&global);
	my_exit(&global);
	return (0);
}
