/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PARSE.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 22:28:50 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/12 22:32:05 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 	PARSE/JOIN								│
//  ├───────────────────────────────────────────────────────────────────────┤
static char *join(char *s1, const char *s2) 
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