/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _CREATE_THREADS.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 22:36:17 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/18 13:50:07 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 	THREADS									│
//  ├───────────────────────────────────────────────────────────────────────┤

static void start(t_universal *global)
{
	int start;

	start = 0;
	pthread_mutex_lock(&global->start_mutex);
	start = global->started;
	pthread_mutex_unlock(&global->start_mutex);
}

static int	grim_reaper(long unsigned time, t_phil *current,
			t_universal *global, int *feasted)
{
	int				end;
	long unsigned	last_eat;

	end = 0;
	pthread_mutex_lock(&current->last_eat_mutex);
	last_eat = current->last_eat;
	pthread_mutex_unlock(&current->last_eat_mutex);
	(void)time;
	if (time > last_eat && ((time - last_eat))
		> (long unsigned)(global->die_t * 1000))
	{
		pthread_mutex_lock(&global->end_mutex);
		pthread_mutex_lock(&current->id_mutex);
		global->end++;
		end = global->end;
		printf("%lu\t%d\t%s\n", (time - global->start) / 1000,
			current->id + 1, "died");
		pthread_mutex_unlock(&current->id_mutex);
		pthread_mutex_unlock(&global->end_mutex);
		usleep(500);
		return (end);
	}
	pthread_mutex_lock(&current->eat_count_mutex);
	if (current->eat_count >= global->eat_c)
		(*feasted)++;
	pthread_mutex_unlock(&current->eat_count_mutex);
	return (end);
}

static void	*end_sim(void *arg)
{
	t_universal	*global;
	int			i;
	int			done;
	int			end;

	global = (t_universal *)arg;
	end = 0;
	start(global);
	while (!end)
	{
		pthread_mutex_lock(&global->end_mutex);
		end = global->end;
		pthread_mutex_unlock(&global->end_mutex);
		i = -1;
		done = 0;
		while (++i != global->phil_num && !end)
			end = grim_reaper(get_time(), global->structs[i], global, &done);
		if (done >= global->phil_num && global->eat_c != 0 && !end)
		{
			pthread_mutex_lock(&global->end_mutex);
			global->end++;
			pthread_mutex_unlock(&global->end_mutex);
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
				my_exit(global);
		current->id = c;
		global->structs[c] = current;
		current->last_eat = global->start;
		current->eat_count = 0;
		current->global = global;
		pthread_mutex_init(&current->last_eat_mutex, NULL);
		pthread_mutex_init(&current->eat_count_mutex, NULL);
		(global->structs)[current->id] = current;
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
