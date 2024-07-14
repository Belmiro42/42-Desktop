/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _PHILOSOPHER.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:37:43 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/14 01:30:04 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							PHILOSOPHER ACTIONS							│
//  ├───────────────────────────────────────────────────────────────────────┤
static void	philosopher_print(t_phil *current, char *str)
{
	unsigned long	time;
	int				id;
	pthread_mutex_t	*print;

	id = current->id + 1;
	time = current->global->start / 1000;
	print = &(current->global->print);
	if (!(current->global->end))
	{
		pthread_mutex_lock(print);
		printf("%lu\t%d\t%s\n", get_time() / 1000 - time, id, str);
		pthread_mutex_unlock(print);
	}
}

static void	philosopher_think(t_phil *current)
{
	philosopher_print(current, "is thinking");
}

static void	philosopher_eat(t_phil *current, pthread_mutex_t *l,
		pthread_mutex_t *r)
{
	long unsigned	time;

	pthread_mutex_lock(r);
	philosopher_print(current, "has taken fork 1");
	time = get_time();
	if (current->global->phil_num != 1)
	{
		pthread_mutex_lock(l);
		time = get_time();
		philosopher_print(current, "has taken fork 2");
		current->last_eat = time;
		philosopher_print(current, "is eating");
		while (get_time() < time + current->global->eat_t * 1000)
		{
		}
		current->eat_count += 1;
		pthread_mutex_unlock(l);
	}
	while (get_time() < time + current->global->die_t * 1000
		&& current->global->phil_num == 1)
	{
	}
	pthread_mutex_unlock(r);
}

static void	philosopher_sleep(t_phil *current)
{
	long unsigned	time;

	time = get_time();
	philosopher_print(current, "is sleeping");
	while (get_time() < time + current->global->sleep_t * 1000)
	{
	}
}

void	*philosopher(void *arg)
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_phil			*current;

	current = (t_phil *)arg;
	(current->global->structs)[current->id] = current;
	left_fork = &(current->global->forks)[(current->id)];
	right_fork = &(current->global->forks)[(current->id + 1)
		% (current->global->phil_num)];
	wait_till_start(current);
	while (!(current->global->end))
	{
		philosopher_think(current);
		philosopher_eat(current, left_fork, right_fork);
		philosopher_sleep(current);
	}
	return (NULL);
}
