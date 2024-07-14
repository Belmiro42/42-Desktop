/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _PARSE.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 22:28:50 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/14 02:14:14 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Philosophers.h"

//  ┌───────────────────────────────────────────────────────────────────────┐
//  │							 	PARSE/JOIN								│
//  ├───────────────────────────────────────────────────────────────────────┤
int	free_string(char **argv)
{
	int	iterator;

	iterator = -1;
	if (argv[0])
	{
		iterator = 0;
		while (argv[iterator])
			iterator++;
		while (--iterator >= 0)
			free(argv[iterator]);
	}
	free(argv);
	return (0);
}

static char	*join(char *s1, const char *s2)
{
	char	*ptr;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = phil_strlen(s1) + phil_strlen(s2) + 1;
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (free(s1), NULL);
	phil_strlcpy(ptr, s1, len + 1);
	ptr[phil_strlen(s1)] = ' ';
	phil_strlcpy(ptr + phil_strlen(s1) + 1, s2, len - phil_strlen(s1));
	free(s1);
	return (ptr);
}

static char	*join_all_inputs(char ***argv)
{
	char	*str;

	str = (char *)malloc(1);
	if (!str)
		my_exit(NULL);
	str[0] = '\0';
	while (**argv)
	{
		str = join(str, **argv);
		if (str == NULL)
			my_exit(NULL);
		(*argv)++;
	}
	return (str);
}

void	parse_input(int *argc, char ***argv)
{
	*argv = phil_split(join_all_inputs(argv), ' ', argc);
}
