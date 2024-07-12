/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:16:01 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/12 22:36:13 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"


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


//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 	MAIN									│
//  ├───────────────────────────────────────────────────────────────────────┤
int main(int argc, char **argv)
{
	t_universal global;

	parse_input(&argc, &argv);
	initialise_struct(&global, argv);
	create_threads(&global);
	my_exit(&global,1,1,1);
	return (0);
}