/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   INITIALISE                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 22:33:01 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/12 22:36:09 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

static t_phil **philosophers_struct_set_up(t_universal *global)
{
	t_phil **structs;

	structs = malloc(global->phil_num * sizeof(t_phil *));
	return (structs);
}

static pthread_mutex_t *forks_set_up(t_universal *global)
{
    pthread_mutex_t *mutexes;
    mutexes = (pthread_mutex_t *)malloc((global->phil_num + 1)* sizeof(pthread_mutex_t));
    if (mutexes == NULL) 
	{
        printf("Failed to allocate memory for mutexes");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < global->phil_num + 1; i++) 
	{
        if (pthread_mutex_init(&mutexes[i], NULL) != 0) 
		{
            printf("MUTEX INIT FAILED");
			exit(EXIT_FAILURE);
        }
    }
	return (mutexes);
}
																			//Write this in a single function!
static pthread_t *create_individual_philosopher()
{
	pthread_t *philosopher;
	
	philosopher = malloc(sizeof(pthread_t));
    return (philosopher);
}

static pthread_t **philosophers_set_up(t_universal *global)
{
	pthread_t **array;
	int iterator;

	array = malloc(sizeof(pthread_t *) * (global->phil_num + 1));
	if (array == NULL) 
		return NULL;
	iterator = -1;
	while(++iterator <= global->phil_num)
		array[iterator] = create_individual_philosopher();
	return (array);
}
																			//free argv here
void initialise_struct(t_universal *global, char **argv)
{	
	int iterator;
	
	global->phil_num = phil_atoi(argv, 1);
	global->die_t = phil_atoi(argv, 2);
	global->eat_t = phil_atoi(argv, 3);
	global->sleep_t = phil_atoi(argv, 4);
	global->eat_c = phil_atoi(argv, 5);
	iterator = 5;
	while(--iterator >= 0)
		free(argv[iterator]);
	free(argv);
	global->start = get_time() + 1000000;
	global->forks = forks_set_up(global);
	global->print = (global->forks)[global->phil_num];
	global->philosophers = philosophers_set_up(global);
	global->structs = philosophers_struct_set_up(global);
	global->end = 0;
}
