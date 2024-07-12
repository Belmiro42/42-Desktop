/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 23:46:18 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/09 02:46:00 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "Philosophers.h"

void create_threads(t_universal *global, int id)
{
	t_phil *phil = malloc(sizeof(t_phil));
	if (!phil) 
		my_exit("PHILOSOPHER CREATION FAILED", global, 1);
	phil->id = id;

	//////////////////////////////////////////////////////////////
	//
	pthread_create(&threads[c], NULL, func, bel); // Create the thread
}

void create_threads(t_universal *global)
{	int	count;

	count = global->phil_num;
	while (count-- != 0)
		create_thread(global, count);
}