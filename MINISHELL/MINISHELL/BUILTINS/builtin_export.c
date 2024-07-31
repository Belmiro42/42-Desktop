/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:04:51 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/31 08:49:40 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// NOTE: export with no options

int export_builtin(char *arg)
{
	key = substring(0, strchr("=")); 											// pseudocode update pls
	value = substring(strchr("="), strlen(arg));								// pseudocode update pls
	free(arg);
	if (KEY_EXISTS(key))
		CHANGE_VALUE_ENV(key, value);
	else
		ADD_KEY_ENV(key, value);
	return(SUCCESS);
}
/*
DESCRIPTION: SYNOPSIS
	export name[=word]...

	NOTE: En nuestro case
	export name=word
*/