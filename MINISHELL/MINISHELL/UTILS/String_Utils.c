/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String_Utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:29:00 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/08 13:58:07 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
// FUNCTION DESCRIPTION: ITOA TWO FUNCTIONS
static int	ft_numlen(int n, int base)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / base;
		length++;
	}
	return (length);
}
char	*ft_itoa(int n)
{
	int			len;
	char		*ret;
	const char	*digits = "0123456789";

	len = ft_numlen(n, 10);
	if (n < 0)
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ret[len] = 0;
	if (n == 0)
		ret[0] = '0';
	if (n < 0)
		ret[0] = '-';
	while (n)
	{
		if (n > 0)
			ret[--len] = digits[n % 10];
		else
			ret[--len] = digits[n % 10 * -1];
		n /= 10;
	}
	return (ret);
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

// FUNCTION DESCRIPTION: putstr
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	if (n == 0)
		return (0);
	index = 0;
	while (s1[index] == s2[index] && s1[index] && index < n - 1)
	{
		index ++;
	}
	return ((unsigned char)s1[index] - (unsigned char)s2[index]);
}

int	ft_atoi(const char *str)
{
	int		number;
	int		valence;

	valence = 1;
	number = 0;
	while (((*str >= 9 && *str <= 13) || *str == ' ') && *str++)
		;
	if ((*str == '+' || (*str == '-' && valence-- && --valence)) && *str++)
		;
	while ((48 <= *str && *str <= 57))
		number = number * 10 + (*str++ - '0');
	return (number * valence);
}



// ¡¡¡¡¡¡ ALL FUNCTIONS MODIFICADO INC STRJOIN ¡¡¡¡¡¡
// FUNCTION DESCRIPTION: arrlen
int	ft_arrlen(char **arr)
{
	int ret;

	ret = 0;
	while (arr[ret])
		ret++;
	return (ret);
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

// FUNCTION DESCRIPTION: ft_strdup
char	*ft_strdup(const char *str1)
{
	int		len;
	char	*str2;

	if (!str1)
			return(ft_strdup(""));
	len = ft_strlen(str1);
	str2 = malloc(len + 1);
	if (str2 == NULL)
		return (NULL);
	ft_strlcpy(str2, str1, len + 1);
	return (str2);
}
int	arr_len(char **arg)
{
// TODO: TODO: UNTESTED
	int	ret;

	ret = 0;
	while (*(arg++))
		ret++;
	return (ret);
}