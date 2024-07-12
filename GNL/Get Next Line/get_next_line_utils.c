/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 01:46:30 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/05/02 19:34:46 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	index;

	if (!s)
		return (NULL);
	index = -1;
	while (s[++index])
		if (s[index] == c)
			return (s + index);
	return (NULL);
}

char	*ft_strjoin(char *start, char *buff)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!start)
	{
		start = (char *)malloc(1 * sizeof(char));
		start[0] = '\0';
	}
	if (!start || !buff)
		return (NULL);
	ptr = (char *)malloc(1 + ft_strlen(start) + ft_strlen(buff) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = -1;
	while (start && start[++i])
		ptr[i] = start[i];
	j = -1;
	while (buff && buff[++j])
		ptr[i + j] = buff[j];
	ptr[i + j] = '\0';
	free(start);
	return (ptr);
}
