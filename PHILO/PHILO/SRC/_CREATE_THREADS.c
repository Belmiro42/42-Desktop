/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _CREATE_THREADS.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 22:36:17 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/16 07:04:28 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 	THREADS									│
//  ├───────────────────────────────────────────────────────────────────────┤

void	wait_till_start(t_phil *current)
{
	int				third;
	unsigned long	start_time;

	third = 0;
	if (current->global->phil_num % 2 == 1)
		if (current->id == (current->global->phil_num - 1))
			third = 2;
	if (current->global->phil_num == 1)
		third = 0;
	start_time = (current->global->start + (((current->id % 2) + third)
				* current->global->eat_t * 1000));
	phil_wait(start_time);
}

static int	grim_reaper(long unsigned time, t_phil *current,
			t_universal *global, int *feasted)
{
	int end;
	long unsigned last_eat;
	int count;

	pthread_mutex_lock(&current->last_eat_mutex);
	last_eat = current->last_eat;
	pthread_mutex_unlock(&current->last_eat_mutex);
	if (time > last_eat)
	{
		if (((time - last_eat))
			> (long unsigned)(global->die_t * 1000))
		{
			pthread_mutex_lock(&global->end_mutex);
			global->end++;
			pthread_mutex_unlock(&global->end_mutex);
			pthread_mutex_lock(&global->print);
			usleep(1000);
			printf("%lu\t%d\t%s\n", (time - global->start) / 1000,
				current->id + 1, "died");
		}
	}
	pthread_mutex_lock(&current->eat_count_mutex);
	count = current->eat_count;
	pthread_mutex_unlock(&current->eat_count_mutex);
	if (count >= global->eat_c)
		(*feasted)++;
	pthread_mutex_lock(&global->end_mutex);
	end = global->end;
	pthread_mutex_unlock(&global->end_mutex);
	return (end);

}

static void	*end_sim(void *arg)
{
	t_universal	*global;
	int			iterator;
	int			feasted;
	int			end;

	global = (t_universal *)arg;
	end = 0;
		while (get_time() < global->start + global->die_t * 980)
	{
		usleep(1);
	}
	while (!end)
	{
		pthread_mutex_lock(&global->end_mutex);
		end = global->end;
		pthread_mutex_unlock(&global->end_mutex);
		iterator = -1;
		feasted = 0;
		while (++iterator != global->phil_num && !end)
			 end = grim_reaper(get_time(), global->structs[iterator], global,
				&feasted);
		if (feasted >= global->phil_num && global->eat_c != 0 && !end)
		{
			pthread_mutex_lock(&global->end_mutex);
			global->end++;
			pthread_mutex_unlock(&global->end_mutex);
			usleep(1000);
			printf("%lu\t\t%s\n", (get_time() - global->start) / 1000,
				"Philosophers Done Eating...");
		}
	}
	return (NULL);
}

static void	create_thread(t_universal *global, int c)
{
	t_phil	*current;

	if (c == global->phil_num)
		pthread_create((global->philosophers[c]), NULL, end_sim, global);
	else
	{
		current = malloc(sizeof(t_phil));
		if (!current)
		{
			if (c == 0)
				my_exit(global);
			else
				my_exit(global);
		}
		current->id = c;
		global->structs[c] = current;
		current->last_eat = global->start;
		current->eat_count = 0;
		current->global = global;
		pthread_mutex_init(&current->last_eat_mutex, NULL);
		pthread_mutex_init(&current->eat_count_mutex, NULL);
		pthread_mutex_init(&current->struct_mutex, NULL);
		pthread_create((global->philosophers[c]), NULL, philosopher, current);
	}
}

void	create_threads(t_universal *global)
{
	int	c;

	c = -1;
	while (++c <= global->phil_num)
		create_thread(global, c);
	c = -1;
	while (++c <= global->phil_num)
		pthread_join((*(global->philosophers)[c]), NULL);
}
