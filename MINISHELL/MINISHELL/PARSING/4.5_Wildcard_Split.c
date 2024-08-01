/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.5_Wildcard_Split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:14:32 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/01 18:23:19 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../minishell.h"

static int	numstring(char const *s1, char c)
{
	int	count;
	int	is_on_delimiter;
	int quote;

	quote = 0;
	count = 0;
	is_on_delimiter = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		(void)in_quotes(*s1, &quote);
		if (*s1 == c && quote == 0)
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
	int quote;
	int change;

	length = 0;
	quote = 0;
	change = 0;
	while ((quote != 0 || (str[i] != c)) && str[i] != '\0')
	{
		change = in_quotes(str[i], &quote);
		if (change == 0)
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
	int quote;
	int change;

	i = 0;
	j = 0;
	quote = 0;
	change = 0;
	while (str[i] != '\0' && j < l)
	{
		change = in_quotes(str[i], &quote);
		k = 0;
		while (str[i] == c && quote == 0)
			i++;
		ret[j] = (char *)malloc(sizeof(char) * numchar(str, c, i) + 1);
		if (ret[j] == NULL)
			return (freee((char const **)ret, j));
		while ((str[i] != '\0' && !(str[i] == c && quote == 0)))
		{
			change = in_quotes(str[i], &quote);
			if (change == 1)
				i++;
			else
				ret[j][k++] = str[i++];
		}
		ret[j++][k] = '\0';
	}
	ret[j] = 0;
	return (ret);
}

char	**wildcard_split(char const *s, char c)
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