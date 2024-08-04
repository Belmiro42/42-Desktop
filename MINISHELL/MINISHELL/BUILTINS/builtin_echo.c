/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:59:34 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/04 15:55:47 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int echo_builtin(char **args)
{
       char   **arg_cpy;
       bool   n;

       n = false;
       arg_cpy = args;
       arg_cpy++;
       if (ft_strcmp(*arg_cpy, "-n", 3) == 0)
              n = true;
       else
              ft_putstr_fd(1, *arg_cpy);
       arg_cpy++;
       while  (*arg_cpy)
              ft_putstr_fd(1, *(arg_cpy++));
       if (n)
              ft_putstr_fd(1, *(arg_cpy++));
}



//DESCRIPTION:
//       -n     do not output the trailing newline
//       All inputs are space seperated.
//       Does not take into accout input files.
//       * / * for directories but says not manage unspecified special characters
