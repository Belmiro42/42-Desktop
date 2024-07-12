/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 02:01:19 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/05/28 11:13:24 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*return_line(char *text_cache)
{
	size_t	index;
	char	*return_line;

	if (!text_cache || !text_cache[0])
		return (NULL);
	index = 0;
	while (text_cache[index] && text_cache[index] != '\n')
		index++;
	index += (text_cache[index] == '\n');
	return_line = malloc((index + 1) * sizeof(char));
	if (!return_line)
		return (NULL);
	index = -1;
	while (text_cache[++index] && text_cache[index] != '\n')
		return_line[index] = text_cache[index];
	if (text_cache[index] == '\n')
		return_line[index++] = '\n';
	return_line[index] = '\0';
	return (return_line);
}

static char	*move_buffer(char *old_text)
{
	size_t	index_old;
	size_t	index_new;
	char	*new_text;

	index_old = 0;
	while (old_text[index_old] && old_text[index_old] != '\n')
		index_old++;
	if (old_text[index_old] == '\0')
	{
		free(old_text);
		return (NULL);
	}
	index_old += (old_text[index_old] == '\n');
	new_text = malloc((ft_strlen(old_text) - index_old + 1) * sizeof(char));
	if (!new_text)
		return (NULL);
	index_new = -1;
	while (old_text[index_old + ++index_new])
		new_text[index_new] = old_text[index_old + index_new];
	new_text[index_new] = '\0';
	free(old_text);
	return (new_text);
}

char	*get_next_line(int fd)
{
	static char	*text_caches[1024] = {NULL};
	char		*current_read;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	current_read = malloc((BUFFER_SIZE + bytes) * sizeof(char));
	if (!current_read)
		return (NULL);
	while (bytes != 0 && !(ft_strchr(text_caches[fd], '\n')))
	{
		bytes = read(fd, current_read, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(current_read);
			return (NULL);
		}
		current_read[bytes] = '\0';
		text_caches[fd] = ft_strjoin(text_caches[fd], current_read);
	}
	free(current_read);
	current_read = return_line(text_caches[fd]);
	text_caches[fd] = move_buffer(text_caches[fd]);
	return (current_read);
}

/*
#include <fcntl.h>
#include <stdio.h>

int main()
{
	char	*str;
	int		fd1;
	int		fd2;

	fd1 = open("Quijote.txt", O_RDONLY);
	fd2 = 0;
	printf("%d", fd1);
	printf("%d", fd2);
	str = "aa";
	while (str)
	{
		str = get_next_line(fd2);
		printf("%s", str);
		free(str);
		str = get_next_line(fd1);
		printf("%s", str);
		free(str);
	}
	system("leaks a.out");
	close(fd1);
	close(fd2);
}*/
