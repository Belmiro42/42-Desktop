/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Initialise_Environment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:14:29 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/05 23:25:19 by bmatos-d         ###   ########.fr       */
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

	environment_variables = NULL;
	environment_variables = malloc(sizeof(t_env));
	environment_variables->next = NULL;
	environment_variables->key = ft_strdup("?");
	environment_variables->value = ft_strdup("0");
	while (*real_variables)
	{
		key = ft_substr(*(real_variables), 0, ft_strnstr(*real_variables,
					"=", strlen(*real_variables)) - *(real_variables));
		create_env_nodes(key, &environment_variables);
		real_variables++;
	}
	return (environment_variables);
}
