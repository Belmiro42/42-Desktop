/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:04:08 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/30 16:32:11 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 

/*
DESCRIPTION:
unset [-fv] name...

NOTE: In our case
unset name

If neither -f nor -v is specified, name refers to a variable; if a variable by that name does not exist, it is unspecified whether a function by that name, if any, shall be unset.

Unsetting a variable or function that was not previously set shall not be considered an error and does not cause the shell to abort.

*/