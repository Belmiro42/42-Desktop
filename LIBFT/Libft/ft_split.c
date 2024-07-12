/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:43:59 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/03/24 20:17:32 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numstring(char const *s1, char c)
{
	int	count;
	int	is_on_delimiter;

	count = 0;
	is_on_delimiter = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			is_on_delimiter = 0;
		else if (is_on_delimiter == 0)
		{
			is_on_delimiter = 1;
			count++;
		}
		s1++;
	}
	return (count);
}

static int	numchar(char const *str, char c, int i)
{
	int	length;

	length = 0;
	while (str[i] != c && str[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}

static char	**freee(char const **dst, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)dst[j]);
	}
	free(dst);
	return (NULL);
}

static char	**affect(char const *str, char **ret, char c, int l)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (str[i] != '\0' && j < l)
	{
		k = 0;
		while (str[i] == c)
			i++;
		ret[j] = (char *)malloc(sizeof(char) * numchar(str, c, i) + 1);
		if (ret[j] == NULL)
			return (freee((char const **)ret, j));
		while (str[i] != '\0' && str[i] != c)
			ret[j][k++] = str[i++];
		ret[j][k] = '\0';
		j++;
	}
	ret[j] = 0;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		l;

	if (s == NULL)
		return (NULL);
	l = numstring(s, c);
	dst = (char **)malloc(sizeof(char *) * (l + 1));
	if (dst == NULL)
		return (NULL);
	return (affect(s, dst, c, l));
}
