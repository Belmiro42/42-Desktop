/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_Wildcard_Expansion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 03:01:41 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/01 09:01:46 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void find_prefix(char *str, char **prefix, int *back)
{
	*prefix = strdup(" ");
	//printf("START 1\t  %d\n", *back);
	if (*back != 0)
		while(ft_isspace(str[--(*back)]) && *back >= 1)
			;
	//printf("START 2\t  %d\n", *back);
	if (str[*back] == '<')
	{
		*prefix = ft_strjoin(*prefix, "<", DEL, KEEP);
		if (*back >= 1)
			if (str[--(*back)] == '<')
				*prefix = ft_strjoin(*prefix, "<", DEL, KEEP);
	//printf("START 3\t  %d\n", *back);
	}
	else if (str[*back] == '>')
	{
		*prefix = ft_strjoin(*prefix, ">", DEL, KEEP);
		if (*back >= 1)
			if (str[--(*back)] == '>')
				*prefix = ft_strjoin(*prefix, ">", DEL, KEEP);
	//	printf("START 4\t  %d\n", *back);
	}
	else
		(*back) += 2;
	//printf("START 5\t  %d\n", *back);
	*prefix = ft_strjoin(*prefix, " ", DEL, KEEP);
	//printf("PREFIX %s\n", *prefix);
}

void find_all_matching(char **matching, char *prefix, char **insert)
{
	char cwd[4097];
	char *current;
	struct dirent *entry;

	getcwd(cwd, 4096);
	DIR *dir = opendir(cwd); 													// TODO: PROTECT
	while ((entry = readdir(dir)) != NULL)
	{
		current = strdup(entry->d_name);
		int index = 0;
		while (matching[index])
		{
			current = ft_strnstr(current, matching[index++], strlen(current));
			if (current == NULL)
				break;
		}
		if (current)
			*insert = ft_strjoin(*insert, ft_strjoin(prefix, ft_strjoin("\'", ft_strjoin(strdup(entry->d_name), "\'", DEL, KEEP), KEEP, DEL), KEEP, DEL), DEL, DEL);
	}
	closedir(dir);
}

char *find_pattern(char *str, int *iterator, int *start)
{
	int change;
	int quotes;

	quotes = 0;
	*start = *iterator;
	while (str[*start] != ' ' && str[*start] != '<' && str[*start] != '>'
		&& *start >= 0)
			change = in_quotes(str[(*start)--], &quotes);
	while ((str[(*iterator)] != ' ' && str[(*iterator)] != '<' &&
		str[(*iterator)] != '>' && str[(*iterator)] != '\0') || quotes != 0)
		change = in_quotes(str[(*iterator)++], &quotes);
	//printf("START%d\n", *start);
	(void)(*start)++;
	//printf("START%d\n", *start);
	(void)(*iterator);
																				//HERE FIND WHETHER ITS ARG OR INPUT OUTPUT
																				//TRACE start TO NON-WHITESPACE CHARACTER OR START OF INPUT
	return (ft_substr(str, *start, *iterator - *start));
}
char *output_insert(char *str, int temp, int start, char *out)
{
	if (temp == 0)
		out = ft_strjoin(out, ft_substr(str, temp, start - temp), DEL, DEL);
	else if (start < temp)
		out = ft_strjoin(out, ft_substr(str, temp + 1, ft_strlen(str) - temp), DEL, DEL);
	else
		out = ft_strjoin(out, ft_substr(str, temp + 1, start - temp - 1), DEL, DEL);
	return (out);
}

char *expand_wildcards(char *str)
{
	int	iterator;
	int quotes;
	int change;
	int	start;
	int temp;
	char *insert;
	char *prefix;;
	char *pattern;
	char *output = ft_strdup("");
	char **matching;

	iterator = 0;
	quotes = 0;
	start = 0;
	temp = 0;

	//printf("%s\n\n", str);
/*	int strint = 0;
	while (strint < strlen(str))
	{
		printf("%d\t%c\n", strint, str[strint]);
		strint++;
	}*/
	while(str[iterator])
	{
		change = in_quotes(str[iterator], &quotes);
		if (str[iterator] == '*' && quotes == 0)
		{
			insert = ft_strdup("");
			pattern = find_pattern(str, &iterator, &start);
			//printf("START%d\n", start);
			find_prefix(str, &prefix, &start);
			//printf("TEMP %d\tSTART %d\tITER %d\n", temp, start, iterator);
			output = output_insert(str, temp, start, output);
			//printf("OUTPUT %s\n", output);
			matching = wildcard_split(pattern, '*');
			int index = 0;
			while (matching[index])
				index++;
			find_all_matching(matching, prefix, &insert);
			temp = iterator -1;
			if (strlen(insert) > 1 )
				printf("INSERT %s\n", insert);
			output = ft_strjoin(output, insert, 1, 1);
			//printf("OUTPUT %s\n\n", output);
		}
		iterator++;
	}
	//printf("Temp %d\tStart %d\tLen %d\n", temp, start, (int)strlen(str));
	output = ft_strjoin(output, ft_substr(str, temp + 1, strlen(str) - temp - 1), 1, 1);
	//printf("FINAL %s\n", output);
	return(output);
}
