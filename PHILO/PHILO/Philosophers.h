/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 02:44:52 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/12 22:39:25 by bmatos-d         ###   ########.fr       */
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
	t_phil			**structs;
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


long unsigned	get_time();
void			free_string(char **argv);
size_t			phil_strlen(const char *s);
size_t			phil_strlcpy(char *dst, const char *src, size_t buff_size);
size_t			phil_strlcat(char *dst, const char *src, size_t buff_size);
long unsigned	get_time();
void			wait_till_start(t_phil *current);
void			*philosopher(void *arg);
void			my_exit(t_universal *global, int structs, int philosophers, int forks);
char			**phil_split(char *s, char c, int *argc);
void			parse_input(int *argc, char ***argv);
void			create_threads(t_universal *global);
void			initialise_struct(t_universal *global, char **argv);
int				phil_atoi(char **argv, int c);