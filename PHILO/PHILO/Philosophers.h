/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 02:44:52 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/11 02:49:07 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_phil t_phil;
typedef struct s_universal t_universal;

typedef struct s_universal
{
	pthread_mutex_t print;
	pthread_mutex_t *forks;
	pthread_t		**philosophers;
	t_phil			**phil_structs;
	int				test;
	int				phil_num;
	int				die_t;
	int				eat_t;
	int				sleep_t;
	int				eat_c;
	long unsigned	start;
	int				end;
}	t_universal;

typedef struct s_phil
{
	t_universal		*global;
	int				id;
	long unsigned	last_eat;
	int				eat_count;
}	t_phil;

void wait_till_start(t_phil *current);
