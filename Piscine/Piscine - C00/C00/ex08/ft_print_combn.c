/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:25:44 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/20 16:28:31 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print(int *arr, int total)
{
    int count;
    char character;
    count = 0;
    while(count < total)
    {
        character = arr[count] + '0';
        write(1, &character,1);
        count++;
    }
    write(1, "\n", 1);
}

void nest(int *arr, int total, int index, int preval)
{
    int value;
    value = preval + 1;
    while( value < 10)
    {
        arr[index] = value;
        if(index < total - 1)
        {
            nest(arr, total, (index + 1), (value));
        }
        else
        {
            print(arr, total);    
        }
        value++;
    }
}

void ft_print_combn(int n)
{
    int arr[n];
    nest(arr, n, 0, -1);
}

/*
int main() {
    ft_print_combn(5);
    return 0;
}
*/
