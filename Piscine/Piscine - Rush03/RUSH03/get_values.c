/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:49:45 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/24 16:17:04 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>

//DELETE ME
char *getvalue(int nb)
{
    return("HI");
}

void count1(int nb, char *str)
{
    // vaciar temp
    char
	if (( nb / 10) != 0)
	{
        //dar valor a temp
        temp = "-";
        strcat(temp, str);
        strcpy(str, temp);
    
	}
	//DEFINE FUNCTION
	temp = getvalue((nb % 10));
	if ((nb % 10) > 0) 
	{
		//DEFINE FUNCTION
		strcat(temp, str);
        strcpy(str, temp);
	}
}

void count2(int nb, char *str)
{
    //DEFINE FUNCTION
    temp = getvalue(((nb % 10) % 10));
    if (((nb % 10) % 10) > 0)
    {
        //DEFINE FUNCTION
        strcat(temp, str);
        strcpy(str, temp);
    }
    if ((((nb % 10) % 10) % 10) > 0 && (((nb % 10) % 10) > 0 || (nb % 10) > 0))
        {
            temp = "and ";
            strcat(temp, str);
            strcpy(str, temp);
        }
                            
}

void count3(int nb, char *str)
{
    //DEFINE FUNCTION
    temp = getvalue(((nb % 10) % 10)% 10);
    strcat(temp, " ");
    strcat(temp, getvalue(100));
    
    if ((((nb % 10) % 10) % 10) > 0)
    {
        //DEFINE FUNCTION
        strcat(temp, str);
        strcpy(str, temp);
    }
}

void three_block_text(int nb, char *str)
{	int count;
    
	count=1;
	while (count != 4)
	{
		if (count == 1)
		{
			count1(nb, str, temp);
		}
		if (count == 2)
		{
			count2(nb, str, temp);
		}
		if (count == 3)
		{
			count3(nb, str, temp);
		}
		count++;
	}
}

void print_str(char *str)
{
    char character;
    
    while(*str)
    {
        character = *str;
        write(1, &character, 1);
        str++;
    }
}

int ft_iterative_power(int nb, int power)
{
    int returnn;
    
    returnn = 1;
    if (power<0)
    {
        return(0);
    }
    while (power--> 0)
    {
        returnn *= nb;
    }
    return(returnn);
    

}

void all_text(int nb)
{
    char *temp;
    int count;
    char *str;
    int number;
 
    // ALLOCATE SPACE FOR STRING USING MALLOC
    str = (char*) malloc(1000 * sizeof(char));

    count = 0;
    while (nb > 0)
    {
        if (count != 0)
        {
            //DEFINE FUNCTION
            temp = getvalue(ft_iterative_power(10, count));
            strcat(temp, str);
            strcpy(str, temp);
        }
        number = ((nb%10) + ((nb%100)*10) + (nb%1000)*100);
        three_block_text(number, str, temp);
        strcat(temp, str);
        strcpy(str, temp);
        count += 3;
        nb /= 1000;
    }
    print_str(str);
    free(str);
}

int main(void)
{
    all_text(123);
    return(1);
}
