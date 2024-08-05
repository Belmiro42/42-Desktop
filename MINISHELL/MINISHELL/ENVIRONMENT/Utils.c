/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 07:54:09 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/05 23:43:40 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_val_env(char *key, t_env *environment)
{
	t_env	*cpy;

	cpy = environment;
	while (cpy)
	{
		if (ft_strncmp(cpy->key, key, ft_strlen(key)) == 0)
			return (ft_strdup(cpy->value));
		cpy = cpy->next;
	}
	return (NULL);
}

void	new_val_env(char *key, char *new_val, t_env *environment)
{
//TODO: UNTESTED
	t_env	*cpy;
	t_env	*new;

	cpy = environment;
	while (cpy)
	{
		if (strcmp(cpy->key, key) == 0)
		{
			free(cpy->value);
			cpy->value = ft_strdup(new_val);
			return ;
		}
		cpy = cpy->next;
	}
	cpy = environment;
	while (cpy->next)
		cpy = cpy->next;
	new = malloc(sizeof(t_env));
	new->key = ft_strdup(key);
	new->value = ft_strdup(new_val);
	new->next = NULL;
	cpy->next = new;
}

bool	key_exists_env(char *key, t_env *environment)
{
	if (get_val_env(key, environment))
		return (true);
	return (false);
}

void	del_var_env(char *key, t_env **environment)
{
// TODO: TODO: UNTESTED
	t_env	*cpy;
	t_env	*tmp;

	cpy = *environment;
	tmp = NULL;
	while (cpy)
	{
		if (ft_strncmp(cpy->key, key, ft_strlen(key)) == 0)
		{
			if (tmp == NULL)
				*environment = cpy->next;
			else
				tmp->next = cpy->next;
			free(cpy->key);
			free(cpy->value);
			free(cpy);
		}
		tmp = cpy;
		cpy = cpy->next;
	}
}
