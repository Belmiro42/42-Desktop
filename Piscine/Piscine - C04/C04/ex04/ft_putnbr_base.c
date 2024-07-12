/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 04:35:38 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/04/14 13:31:34 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

static int check_radix(char *str)
{
	int	len;
	int	i;
	int j;

	len = ft_strlen(str);
	if (len<2)
		return (0);
	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == '+' || str[i] == '-')
			return (0);
		while (str[j])
		{
			if (!((str + i) == (str + j)) && str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int recursivepower(int nb, int power, int ret)
{
	if (power != 0)
		ret = recursivepower(nb, power - 1, ret);
	return (ret * nb); 

}

static void	ft_putnbrr(int nb, int base, char *bass)
{
	long int	n;
	char		chara;

	n = (long int)nb;
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	if ((n / base) > 0)
		ft_putnbr(n / base);
	chara = bass[(n % base)] + '0';
	write(1, &chara, 1);
}

void ft_putnbr_base(int nbr, char *base);
{
	int base_ c;
	
	if (!check_radix(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	base_c = ft_strlen(base);
	ft_putnbrr(nbr, base_c)
} 