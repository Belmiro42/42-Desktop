/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:16:01 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/14 02:52:55 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

int	main(int argc, char **argv)
{
	t_universal	global;

	global.forks = NULL;
	global.philosophers = NULL;
	global.structs = NULL;
	parse_input(&argc, &argv);
	initialise_struct(&global, argv);
	create_threads(&global);
	my_exit(&global);
	return (0);
}
