/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_power.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:30:01 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/23 21:35:16 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_iterative_power(int nb, int power)
{
    int returnn;

    returnn = 1;
    while (power--> 0)
    {
        returnn *= nb;
    }
    return(returnn);
    if (power<0)
    {
        return(0);
    }

}

/*
int main(void)
{
	int a;
	int character;

    a = ft_iterative_power(10, 6);
	while(a!=0)
	{
		character = (a % 10) + '0';
		write(1, &character, 1);
		a /= 10;
	}

    return(0);
}
*/
