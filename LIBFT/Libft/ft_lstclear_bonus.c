/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 21:33:09 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/03/28 22:10:56 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cpy;
	t_list	*cpycpy;

	if (!*lst)
		return ;
	cpy = *lst;
	while (cpy)
	{
		cpycpy = cpy->next;
		ft_lstdelone(cpy, del);
		cpy = cpycpy;
	}
	*lst = NULL;
}
