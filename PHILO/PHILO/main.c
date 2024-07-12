/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:16:01 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/12 12:50:49 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 	SPLIT									│
//  ├───────────────────────────────────────────────────────────────────────┤
static int numstring(char const *s1, char c) 
{
	int count = 0;
	int is_on_delimiter = 0;

	if (*s1 == '\0')
		return 0;

	while (*s1 != '\0') {
		if (*s1 == c)
			is_on_delimiter = 0;
		else if (is_on_delimiter == 0) {
			is_on_delimiter = 1;
			count++;
		}
		s1++;
	}
	return count;
}
static int numchar(char const *str, char c, int i) 
{
	int length = 0;
	while (str[i] != c && str[i] != '\0') {
		length++;
		i++;
	}
	return length;
}
static char **freee(char **dst, int j) 
{
	while (j > 0) {
		j--;
		free(dst[j]);
	}
	free(dst);
	return NULL;
}
static char **affect(char *str, char **ret, char c, int l) 
{

	int i = 0, j = 0, k;
	while (str[i] != '\0' && j < l) {
		k = 0;
		while (str[i] == c)
			i++;
		ret[j] = (char *)malloc(sizeof(char) * numchar(str, c, i) + 1);
		if (ret[j] == NULL)
			return freee(ret, j);
		while (str[i] != '\0' && str[i] != c)
			ret[j][k++] = str[i++];
		ret[j][k] = '\0';
		j++;
	}
	ret[j] = NULL;
	free(str);
	return ret;
}
char **phil_split(char *s, char c, int *argc) 
{
	char **dst;
	int l;

	if (s == NULL)
		return NULL;

	l = numstring(s, c);
	if (l !=6 && l != 5)
	{
		printf("FIX ME: MY EXIT\n");
		free(s);
		exit(EXIT_FAILURE);
		//my_exit("VARIABLE COUNT WRONG");
	}
	*argc = l;
	dst = (char **)malloc(sizeof(char *) * (l + 1));
	if (dst == NULL)
		return NULL;

	return affect(s, dst, c, l);
}
//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 	UTILS									│
//  ├───────────────────────────────────────────────────────────────────────┤
size_t phil_strlen(const char *s)
{
	size_t index = 0;
	while (s[index])
		index++;
	return index;
}
size_t phil_strlcpy(char *dst, const char *src, size_t buff_size) 
{
	size_t index = 0;
	if (buff_size == 0)
		return phil_strlen(src);
	while (buff_size > 1 && src[index]) {
		dst[index] = src[index];
		buff_size--;
		index++;
	}
	if (buff_size != 0)
		dst[index] = '\0';
	return phil_strlen(src);
}
size_t phil_strlcat(char *dst, const char *src, size_t buff_size) 
{
	size_t dst_len = phil_strlen(dst);
	size_t src_len = phil_strlen(src);

	if (buff_size <= dst_len)
		return buff_size + src_len;

	return dst_len + phil_strlcpy(dst + dst_len, src, buff_size - dst_len);
}
int phil_atoi(char **argv, int c)
{
	long	number;
	char *str;

	str = argv[c];
	if (str == NULL)
		return (0);
	number = 0;
	while ((48 <= *str && *str <= 57))
	{
		number = number * 10 + (*str++ - '0');
		if (number > INT_MAX || number == 0)
		{
			//freee(argv);
			//my_exit("A VALUE IS BEYOND INT RANGE");
			printf("FIX ME: MY EXIT\n");
			printf("A VALUE IS OUT OF RANGE\n");
			exit(EXIT_SUCCESS);
		}
	}
	if (*str)
	{
		//my_exit("A VALUE IS NOT A NUMBER");
		printf("A VALUE IS NOT A NUMBER");
	}
	return (number);
}
long unsigned get_time()
{
	struct timeval now;

	gettimeofday(&now, 0);
	return ((now.tv_sec * 1000000) + now.tv_usec);	
}
//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 	PARSE/JOIN								│
//  ├───────────────────────────────────────────────────────────────────────┤
char *join(char *s1, const char *s2) 
{
	char *ptr;
	size_t len;

	if (!s1 || !s2)
		return NULL;
	len = phil_strlen(s1) + phil_strlen(s2) + 1; // +1 for space
	ptr = (char *)malloc(len + 1); // +1 for null terminator
	if (ptr == NULL)
	{
		free(s1);
		return NULL;
	}
	phil_strlcpy(ptr, s1, len + 1);
	ptr[phil_strlen(s1)] = ' ';
	phil_strlcpy(ptr + phil_strlen(s1) + 1, s2, len - phil_strlen(s1));
	free(s1);
	return ptr;
}
static char *join_all_inputs(char ***argv)
{
	char *str;

	str = (char *)malloc(1);
	if (!str) {
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
	str[0] = '\0';

	while (**argv) {
		str = join(str, **argv);
		if (str == NULL) {
			perror("join failed");
			exit(EXIT_FAILURE);
		}
		(*argv)++;
	}
	return str;
}
void parse_input(int *argc, char ***argv) 
{

	*argv = phil_split(join_all_inputs(argv), ' ', argc);
}
//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 	INITIALISE								│
//  ├───────────────────────────────────────────────────────────────────────┤
																			//Protect the mallocs of all functions using my!
t_phil **philosophers_struct_set_up(t_universal *global)
{
	t_phil **phil_structs;

	phil_structs = malloc(global->phil_num * sizeof(t_phil *));
	return (phil_structs);
}
pthread_mutex_t *forks_set_up(t_universal *global)
{
    pthread_mutex_t *mutexes;
    mutexes = (pthread_mutex_t *)malloc((global->phil_num + 1)* sizeof(pthread_mutex_t));
    if (mutexes == NULL) 
	{
        printf("Failed to allocate memory for mutexes");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < global->phil_num; i++) 
	{
        if (pthread_mutex_init(&mutexes[i], NULL) != 0) 
		{
            printf("MUTEX INIT FAILED");
			exit(EXIT_FAILURE);
        }
    }
    //for (int i = 0; i < n; i++) {
    //    pthread_mutex_destroy(&mutexes[i]);
    //}
    //free(mutexes);
	return (mutexes);
}
																			//Write this in a single function!
pthread_t *create_individual_philosopher()
{
	pthread_t *philosopher = malloc(sizeof(pthread_t));
    return (philosopher);
}
pthread_t **philosophers_set_up(t_universal *global)
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
	global->phil_num = phil_atoi(argv, 1);
	global->die_t = phil_atoi(argv, 2);
	global->eat_t = phil_atoi(argv, 3);
	global->sleep_t = phil_atoi(argv, 4);
	global->eat_c = phil_atoi(argv, 5);
	global->start = get_time() + 2000000;
	global->forks = forks_set_up(global);
	global->print = (global->forks)[global->phil_num];
	global->philosophers = philosophers_set_up(global);
	global->phil_structs = philosophers_struct_set_up(global);
	global->end = 0;
}
//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							PHILOSOPHER ACTIONS							│
//  ├───────────────────────────────────────────────────────────────────────┤
void philosopher_print(t_phil *current, char *str)
{
	unsigned long time;
	int id;
	pthread_mutex_t print;

	id = current->id + 1;
	time = current->global->start / 1000;
	print = current->global->print;
	if (!(current->global->end))
	{
		pthread_mutex_lock(&(print));
		printf("%lu\t%d\t%s\n", get_time() / 1000 - time, id, str);
		pthread_mutex_unlock(&(print));
	}
}
void philosopher_think(t_phil *current)
{
	philosopher_print(current, "is thinking");
}
void philosopher_eat(t_phil *current, pthread_mutex_t *l, pthread_mutex_t *r)
{
	long unsigned time;

	pthread_mutex_lock(&(*l));
	philosopher_print(current, "has taken fork 1"); 
	pthread_mutex_lock(&(*r));
	time = get_time();
	philosopher_print(current, "has taken fork 2");
	current->last_eat = time;
	philosopher_print(current, "is eating");
	while(get_time() < time + current->global->eat_t * 1000)
	{
	}
	current->eat_count += 1;
	pthread_mutex_unlock(&(*r));
	pthread_mutex_unlock(&(*l));
}
void philosopher_sleep(t_phil *current)
{
	long unsigned time;

	time = get_time();
	philosopher_print(current, "is sleeping");
	while (get_time() < time + current->global->sleep_t * 1000)
	{
	}  
}
void *philosopher(void *arg) 
{
	pthread_mutex_t left_fork;
	pthread_mutex_t right_fork;
	t_phil *current;
	
	current = (t_phil *)arg;
	left_fork = current->global->forks[(current->id)];
	right_fork =current->global->forks[(current->id + 1) % (current->global->phil_num)];
	(current->global->phil_structs)[current->id]=current;
	wait_till_start(current);
	while(!(current->global->end))
	{
		philosopher_think(current);
		philosopher_eat(current, &left_fork, &right_fork);
		philosopher_sleep(current);
	}
	return (NULL);
}

//pthread_mutex_unlock(&(current->global->forks)[(current->id)]);
//pthread_mutex_unlock(&(current->global->forks)[(current->id + 1) % (current->global->phil_num)]);
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
void grim_reaper(long unsigned time, t_phil *current, t_universal *global, int *feasted)
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
void *end_sim(void *arg)
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
			grim_reaper(get_time(), global->phil_structs[iterator], global, &feasted);
		if (feasted >= global->phil_num && global->eat_c != 0)
		{
			global->end = 1;
			usleep(1000);
			printf("%lu\t\t%s\n", (get_time() - global->start) / 1000, "Philosophers Done Eating...");
		}
	}
	return (NULL);
}
void create_thread(t_universal *global, int c) 
{
	if (c == global->phil_num)
		pthread_create((global->philosophers[c]), NULL, end_sim, global);
	else
	{
	t_phil *current = malloc(sizeof(t_phil)); // Dynamically allocate memory for the struct
	if (!current) 
	{
		perror("Failed to allocate memory"); // Handle memory allocation failure
		exit(EXIT_FAILURE);
	}
	current->id = c; // Assign the mutex pointer
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
	{
		pthread_join((*(global->philosophers)[c]), NULL); // Wait for all threads to complete
	}
}
//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 	MAIN									│
//  ├───────────────────────────────────────────────────────────────────────┤
int main(int argc, char **argv)
{
	t_universal global;

	parse_input(&argc, &argv);
	//Need to free argv
	initialise_struct(&global, argv);
	create_threads(&global);
	//Check Functions
	//clean();
}