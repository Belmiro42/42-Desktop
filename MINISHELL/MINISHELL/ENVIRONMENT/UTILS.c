/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UTILS.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:29:00 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/31 13:25:34 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// FUNCTION DESCRIPTION: STR_JOIN
// joins two strings together
// frees aswell if you want it to
char *ft_strjoin(char const *s1, char const *s2, bool free1, bool free2)
{
	char *ptr;
	int len;
	// printf("S1: %s \nS2: %s\n", s1, s2);										// DELETE Checker

	if (!s1 && !s2)
		return (NULL);
	if (s2 && !s1)
		return ((char *)s2);
	if (s1 && !s2)
		return ((char *)s1);
	len = strlen(s1) + strlen(s2); // TODO: STRLEN STRCPY AND STRLCAT
	// printf("Len: %d\n", len);												// DELETE Checker
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, len + 1);
	// printf("%s\n", ptr);														// DELETE Checker
	ft_strlcat(ptr, s2, len + 1);
	// printf("%s\n", ptr);														// DELETE Checker
	if (free1 && s1) // NOTE: Añadi este variable para liberar si quieres.
		free((char *)s1);
	if (free2 && s2)
		free((char *)s2);
	// printf("ptr: %s\n\n\n", ptr);											// DELETE Checker
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

// FUNCTION DESCRIPTION: add character
// adds a character to a string
char *add_character(char s1, char *s2, bool free1)
{
	char *ch;
	char *result;

	ch = malloc(sizeof(char) * 2);
	if (!ch)
		return NULL;
	ch[0] = s1;
	ch[1] = '\0';
	result = ft_strjoin(s2, ch, free1, 1);
	return result;
}

// FUNCTION DESCRIPTION: add character
int bels_isspace(char c) 
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
        return (1);
	else
		return (0);
}