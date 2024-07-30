/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:05:02 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/30 15:49:23 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NOTE: pwd with no options

/*
DESCRIPTION: SYNOPSIS
pwd [OPTION]...

NOTE: In our case
pwd

use $PWD but need to manage symlinks. If no option is specified, -P is assumed.
-P, --physical avoid all symlinks

*/