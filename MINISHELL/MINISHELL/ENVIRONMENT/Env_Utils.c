/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Env_Utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 07:54:09 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/02 15:19:07 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *get_val_env(char *key)
{
	t_env *cpy;

	cpy = minishell_env;
	while (cpy)
	{
		if (strcmp(cpy->key, key) == 0)											//  TODO: ft_...
			return (cpy->value);
		cpy = cpy->next;
	}
	return (NULL);
}

void new_val_env(char *key, char *new_val)
{
	t_env *cpy;
	t_env *new;

	cpy = minishell_env;
	while(cpy)
	{
		if (strcmp(cpy->key, key) == 0)
		{
			free(cpy->value);
			cpy->value = ft_strdup(new_val);
			return ;
		}
		cpy = cpy->next;
	}
	cpy = minishell_env;
	while(cpy->next)
		cpy = cpy->next;
	new = malloc(sizeof(t_env));
	new->key = strdup(key);
	new->value = strdup(new_val);
	cpy->next = new;
}

bool key_exists_env(char *key)
{
	if (get_val_env(key))
		return (true);
	return (false);
}
