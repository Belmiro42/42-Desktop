/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_Input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:54:03 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/09 19:17:35 by bmatos-d         ###   ########.fr       */
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
		free(s);
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
size_t phil_strlen(const char *s) {
	size_t index = 0;
	while (s[index])
		index++;
	return index;
}
size_t phil_strlcpy(char *dst, const char *src, size_t buff_size) {
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
size_t phil_strlcat(char *dst, const char *src, size_t buff_size) {
	size_t dst_len = phil_strlen(dst);
	size_t src_len = phil_strlen(src);

	if (buff_size <= dst_len)
		return buff_size + src_len;

	return dst_len + phil_strlcpy(dst + dst_len, src, buff_size - dst_len);
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
static char *join_all_inputs(int argc, char ***argv)
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
void parse_input(int *argc, char ***argv, t_universal *global) 
{
	char *str;

	*argv = phil_split(join_all_inputs(*argc, argv), ' ', argc);
}

