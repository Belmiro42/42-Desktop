/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:25:57 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/04/13 23:19:36 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

/*
int main(void)
{
	char str[] = "aasd";
	char llength = ft_strlen(str) + '0';
	write(1, &llength, 1);
}
*/
