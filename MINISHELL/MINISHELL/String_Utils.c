/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String_Utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:29:00 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/04 00:12:55 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// FUNCTION DESCRIPTION: add character
// adds a character to a string
char *add_character(char character, char *string, bool free_string)
{
	char *char_as_string;
	char *result;

	char_as_string = malloc(sizeof(char) * 2);
	if (!char_as_string)
		return (NULL);
	char_as_string[0] = character;
	char_as_string[1] = '\0';
	result = ft_strjoin(string, char_as_string, free_string, DEL);

	return result;
}
// FUNCTION DESCRIPTION: STR_JOIN
// joins two strings together
// frees aswell if you want it to
char *ft_strjoin(char *s1, char *s2, bool free1, bool free2)
{
	char *ptr;
	int len;

	if (!s1 && !s2)
		return (NULL);
	if (s2 && !s1)
		return (s2);
	if (s1 && !s2)
		return (s1);
	len = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, len + 1);
	ft_strlcat(ptr, s2, len + 1);
	if (free1 && s1) 															// NOTE: Añadi este variable para liberar si quieres.
		free(s1);
	if (free2 && s2)
		free(s2);
	return (ptr);
}
// FUNCTION DESCRIPTION: ft_substr
char	*ft_substr(char const *s, int start, int len)
{
	char	*ptr;

	if (!s )
		return (NULL);
	if (start > (int)ft_strlen(s) || len < 0)
		return (ft_strdup(""));
	if (len > (int)ft_strlen(s + start))
		len = ft_strlen(s + start);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}

// FUNCTION DESCRIPTION: ft_strdup
char	*ft_strdup(const char *str1)
{
	int		len;
	char	*str2;

	if (!str1)
		return (NULL);
	len = ft_strlen(str1);
	str2 = malloc(len + 1);
	if (str2 == NULL)
		return (NULL);
	ft_strlcpy(str2, str1, len + 1);
	return (str2);
}

// FUNCTION DESCRIPTION: ft_strlcpy
size_t	ft_strlcpy(char *dst, const char *src, size_t buff_size)
{
	int	index;

	index = 0;
	while (buff_size > 1 && src[index])
	{
		dst[index] = src[index];
		buff_size--;
		index++;
	}
	if (buff_size != 0)
	{
		dst[index] = '\0';
	}
	return (ft_strlen(src));
}

// FUNCTION DESCRIPTION: ft_strnstr
char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		position;

	if (*to_find == '\0')
		return ((char *)str);
	position = ft_strlen((char *)to_find);
	while (*str != '\0' && len-- >= position)
	{
		if (*str == *to_find && ft_memcmp(str, to_find, position) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

// FUNCTION DESCRIPTION: ft_memcmp
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	index;

	index = 0;
	while (n--)
	{
		if (((unsigned char *)s1)[index] != ((unsigned char *)s2)[index])
			return (((unsigned char *)s1)[index]
					- ((unsigned char *)s2)[index]);
		index++;
	}
	return (0);
}

// FUNCTION DESCRIPTION: ft_strlen
size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index++])
		;
	return (index - 1);
}

// FUNCTION DESCRIPTION: ft_strlcat
int	ft_strlcat(char *dst, const char *src, size_t buff_size)
{
	size_t	index;
	size_t	ret;

	index = 0;
	while (*dst && index < buff_size)
	{
		++dst;
		++index;
	}
	ret = ft_strlcpy(dst, src, buff_size - index);
	return (ret + index);
}

// FUNCTION DESCRIPTION: in_quotes
// Whether we are in simple quotes or doubles quotes.
// 1 DENOTES WE ARE IN SIMPLE QUOTE
// 2 DENOTES WE ARE IN SIMPLE QUOTE
int in_quotes(char c, int *quote)
{
	if (c == '\'' && *quote == 0) 												// NOTE: 1 significa que estamos dentro de simples
		return (*quote = 1, 1);
	else if (c == '\'' && *quote == 1)
		return (*quote = 0, 1);
	if (c == '\"' && *quote == 0) 												// NOTE: 2 significa que estamos dentro de dobles
		return (*quote = 2, 1);
	else if (c == '\"' && *quote == 2)
		return (*quote = 0, 1);
	return (0);
}

// FUNCTION DESCRIPTION: ft_isspace
int ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

// FUNCTION DESCRIPTION: free_dbl
void ft_freedbl(char **twodimmalloc)
{
	int iterator;

	iterator = 0;
	while (twodimmalloc[iterator])
		free(twodimmalloc[iterator++]);
	free(twodimmalloc);
}

// FUNCTION DESCRIPTION: alpha
int	ft_isalpha(unsigned short c)
{
	if ((65 <= c && c <= 90) || (97 <= c && c <= 122))
		return (1);
	return (0);
}

// FUNCTION DESCRIPTION: alphanumerical
int	ft_isalnum(unsigned char c)
{
	if ((65 <= c && c <= 90) || (97 <= c && c <= 122) || (48 <= c && c <= 57))
		return (1);
	return (0);
}

// FUNCTION DESCRIPTION: digit
int	ft_isdigit(unsigned short c)
{
	if (48 <= c && c <= 57)
		return (1);
	return (0);
}