/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:44:21 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/03/20 17:15:33 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *string, char (*f)(unsigned int, char))
{
	char			*new_string;
	unsigned int	index;

	if (!string)
		return (NULL);
	new_string = ft_strdup(string);
	if (!new_string)
		return (NULL);
	index = 0;
	while (new_string[index])
	{
		new_string[index] = f(index, new_string[index]);
		index++;
	}
	return (new_string);
}
