/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_*_Expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 03:01:41 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/09 01:02:16 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	find_prefix(char *str, char **prefix, int *back)
{
	*prefix = ft_strdup(" ");
	if (*back != 0)
		while (ft_isspace(str[--(*back)]) && *back >= 1)
			;
	if (str[*back] == '<')
	{
		*prefix = ft_strjoin(*prefix, "<", DEL, KEEP);
		if (*back >= 1)
			if (str[--(*back)] == '<')
				*prefix = ft_strjoin(*prefix, "<", DEL, KEEP);
	}
	else if (str[*back] == '>')
	{
		*prefix = ft_strjoin(*prefix, ">", DEL, KEEP);
		if (*back >= 1)
			if (str[--(*back)] == '>')
				*prefix = ft_strjoin(*prefix, ">", DEL, KEEP);
	}
	else
		(*back) += 2;
	*prefix = ft_strjoin(*prefix, " ", DEL, KEEP);
}

void	find_all_matching(char **matching, char *prefix, char **insert)
{
	char			*cpy;
	char			*current;
	struct dirent	*entry;
	int				index;
	DIR				*dir;

	cpy = NULL;
	cpy = getcwd(cpy, 0);
	dir = opendir(cpy); // TODO: PROTECT
	free(cpy);
	entry = readdir(dir);
	while (entry != NULL)
	{
		current = strdup(entry->d_name);
		cpy = current;
		index = 0;
		while (matching[index] && current)
		{
			printf("MATCHING %s", matching[index]);
			current = ft_strnstr(current, matching[index++], strlen(current));
		}
		if (current)
			*insert = ft_strjoin(*insert, ft_strjoin(prefix, ft_strjoin("\'",
							ft_strjoin(cpy, "\'", KEEP, KEEP), KEEP, DEL), KEEP,
						DEL), DEL, DEL);
		entry = readdir(dir);
		free(cpy);
	}
	closedir(dir);
	ft_freedbl(matching);
}

char	*output_insert(char *str, int temp, int start, char *out)
{
	if (temp == 0)
		out = ft_strjoin(out, ft_substr(str, temp, start - temp), DEL, DEL);
	else if (start < temp)
		out = ft_strjoin(out, ft_substr(str, temp + 1, ft_strlen(str) - temp),
				DEL, DEL);
	else
		out = ft_strjoin(out, ft_substr(str, temp + 1, start - temp - 1), DEL,
				DEL);
	return (out);
}

char	*find_pattern(char *str, int *iterator, int *start)
{
	int	change;
	int	quotes;

	quotes = 0;
	*start = *iterator;
	while (str[*start] != ' ' && str[*start] != '<' && str[*start] != '>'
		&& *start > 0)
		change = in_quotes(str[(*start)--], &quotes);
	while ((str[(*iterator)] != ' ' && str[(*iterator)] != '<'
			&& str[(*iterator)] != '>' && str[(*iterator)] != '\0')
		|| quotes != 0)
		change = in_quotes(str[(*iterator)++], &quotes);
	(*start)++;
	return (ft_substr(str, *start, *iterator - *start));
}

char	*expand_wildcards(char *str)
{
	int		iterator;
	int		quotes;
	int		change;
	int		start;
	int		temp;
	char	*insert;
	char	*prefix;
	char	*pattern;
	char	*output;
	char	**matching;
	int		strint;

	output = ft_strdup("");
	iterator = 0;
	quotes = 0;
	start = 0;
	temp = 0;
	printf("%s\n\n", str);
	strint = 0;
	while (strint < (int)strlen(str))
	{
		printf("%d\t%c\n", strint, str[strint]);
		strint++;
	}
	while (str[iterator])
	{
		change = in_quotes(str[iterator], &quotes);
		if (str[iterator] == '*' && quotes == 0)
		{
			insert = ft_strdup("");
			pattern = find_pattern(str, &iterator, &start);
			printf("START%d\n", start);
			find_prefix(str, &prefix, &start);
			printf("TEMP %d\tSTART %d\tITER %d\n", temp, start, iterator);
			// output = output_insert(str, temp, start, output);
			printf("OUTPUT %s\n", output);
			matching = wildcard_split(pattern, '*');
			find_all_matching(matching, prefix, &insert);
			temp = iterator - 1;
			// if (strlen(insert) >= 1)
			printf("INSERT %s\n", insert);
			output = ft_strjoin(output, insert, 1, 1);
			printf("OUTPUT %s\n\n", output);
			free(pattern);
			free(prefix);
		}
		if (str[iterator])
			iterator++;
	}
	printf("Temp %d\tStart %d\tLen %d\n", temp, start, (int)strlen(str));
	output = ft_strjoin(output, ft_substr(str, temp, strlen(str) - temp), DEL,
			DEL);
	printf("OUTPUT %s\n", output);
	free(str);
	return (output);
}
