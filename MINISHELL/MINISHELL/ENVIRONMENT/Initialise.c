/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:14:29 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/06 22:48:18 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	create_env_nodes(char *key, t_env **environment_original)
{
	t_env	*current;
	t_env	*cpy;

	current = malloc(sizeof(t_env));
	current->next = NULL;
	current->key = key;
	current->value = ft_strdup(getenv(key));
	cpy = *environment_original;
	while (cpy->next)
		cpy = cpy->next;
	cpy->next = current;
}

t_env	*create_env_variables(char **real_variables)
{
	char	*key;
	t_env	*environment_variables;
	t_env	*next;

	next = malloc(sizeof(t_env));
	next->next = NULL;
	next->key = ft_strdup("!");
	next->value = ft_strdup("0");
	environment_variables = malloc(sizeof(t_env));
	environment_variables->key = ft_strdup("?");
	environment_variables->value = ft_strdup("0");
	environment_variables->next = next;
	next->next = NULL;
	while (*real_variables)
	{
		key = ft_substr(*(real_variables), 0, ft_strnstr(*real_variables,
					"=", strlen(*real_variables)) - *(real_variables));
		create_env_nodes(key, &environment_variables);
		real_variables++;
	}
	return (environment_variables);
}
