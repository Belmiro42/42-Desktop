/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Env_Utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 07:54:09 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/01 09:17:37 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *get_val_env(char *key)
{
	t_env *cpy;

	cpy = &minishell_env;
	while (cpy)
	{
		if (strcmp(cpy->key, key) == 0)											//  TODO: ft_...
			return (cpy->value);
		cpy = cpy->next;
	}
	return (NULL);
}

int change_val_env(char *key, char *new_val)
{
	char *key_val;

	key_val = get_val_env(key);
	if (key_val == NULL)
		return (0);																// TODO: ERROR;
	key_val = ft_strdup(new_val);													// TODO: Check if malloced. If so remove the strdup
	return (1);
}

void add_key_env(char *key, char *val)
{
	t_env *cpy;
	t_env *node;

	if (get_val_env(key))
		{
			change_val_env(key, val);
			return ;
		}
	cpy = &minishell_env;
	while(cpy->next)
		cpy = cpy->next;
	node = malloc(sizeof(t_env));
	node->key = ft_strdup(key);
	node->value = ft_strdup(val);
	node->next = NULL;
	cpy->next = node;
}

bool key_exists_env(char *key)
{
	if (get_val_env(key))
		return (true);
	return (false);
}