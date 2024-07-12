/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:43:32 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/05/02 19:47:18 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int			ft_printf(char const *str, ...);
void		do_x(unsigned int hex, char c,
				unsigned int *index, unsigned int *length);
void		do_u(unsigned int n, unsigned int *index,
				unsigned int *length, unsigned int iteration);
void		do_i(int n, unsigned int *length,
				unsigned int *index, int iteration);
void		do_s(char *c, unsigned int *index, unsigned int *length);
void		do_p(void *number, unsigned int *index, unsigned int *length);
void		do_n(char const *s, unsigned int *index, unsigned int *length);
void		do_c(char c, unsigned int *length, unsigned int *index);

#endif