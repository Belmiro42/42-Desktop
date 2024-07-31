/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:59:34 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/07/31 08:14:39 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//int echo_builtin(char **arg_cpy, bool n)
//{
//       while (arg_cpy)
//       {
//              printf("%s", arg);
//              if (!n)
//                     printf("\n");
//       }
//}




// NOTE: echo with option -n

/*

DESCRIPTION: SYNOPSIS
NOTE:
echo [SHORT-OPTION]... [STRING]...
echo LONG-OPTION

DESCRIPTION: FLAGS
       -n     do not output the trailing newline



NOTE:
       All inputs are space seperated.
       Does not take into accout input files.
       * / * for directories but says not manage unspecified special characters

TRY:
       echo -n "hat" && echo hat
and    echo "hat" && echo hat


*/