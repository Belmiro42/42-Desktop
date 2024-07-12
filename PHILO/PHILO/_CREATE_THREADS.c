/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _CREATE_THREADS.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 22:36:17 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/12 22:38:23 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 	THREADS									│
//  ├───────────────────────────────────────────────────────────────────────┤
void wait_till_start(t_phil *current)
{
	int third;
	unsigned long start_time;

	third = 0;
	if (current->global->phil_num % 2 == 1)
		if (current->id == (current->global->phil_num - 1))
			third = 2;
	if (current->global->phil_num ==  1)
		third = 0;
	start_time = (current->global->start + (((current->id % 2) + third) * current->global->eat_t  * 1000));
	while (get_time() < start_time)
	{
		usleep(1);
	}
}
static void grim_reaper(long unsigned time, t_phil *current, t_universal *global, int *feasted)
{
	if (time > current->last_eat)
	{
		if (((time - current->last_eat)) > global->die_t * 1000)
		{
			global->end = 1;
			usleep(100);
			printf("%lu\t%d\t%s\n", (time - global->start) / 1000, current->id + 1, "died");
		}
	}
	if (current->eat_count >= global->eat_c)
		(*feasted)++;

}																			
																				//Find a way to free Structs
static void *end_sim(void *arg)
{
	t_universal *global;
	int iterator;
	int feasted;
	
	global = (t_universal *)arg;
	while (get_time() < global->start)
	{
	}
	while(!(global->end))
	{
		iterator = -1;
		feasted = 0;
		while (++iterator != global->phil_num && !(global->end))
			grim_reaper(get_time(), global->structs[iterator], global, &feasted);
		if (feasted >= global->phil_num && global->eat_c != 0)
		{
			global->end = 1;
			printf("%lu\t\t%s\n", (get_time() - global->start) / 1000, "Philosophers Done Eating...");

		}
	}
	return (NULL);
}
static void create_thread(t_universal *global, int c) 
{
	if (c == global->phil_num)
		pthread_create((global->philosophers[c]), NULL, end_sim, global);
	else
	{
	t_phil *current = malloc(sizeof(t_phil)); // Dynamically allocate memory for the struct
	if (!current)
	{
		//my_exit
	}
	current->id = c; // Assign the mutex pointer
	global->structs[c] = current;
	current->last_eat = global->start; // Assign the thread identifier
	current->eat_count = 0;
	current->global = global;
	pthread_create((global->philosophers[c]), NULL, philosopher, current); // Create the thread
	}
}
void create_threads(t_universal *global) 
{
	int c = -1;
	while (++c <= global->phil_num)
		create_thread(global, c); 
	c = -1;
	while (++c <= global->phil_num) 
		pthread_join((*(global->philosophers)[c]), NULL); // Wait for all threads to complete
}