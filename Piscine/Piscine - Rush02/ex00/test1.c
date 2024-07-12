/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:13:30 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/18 22:50:27 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void randomisation(int **arr);
void print(int **arr);
void initialise(int **arr);
void clear(int **arr);
void turn(int **arr);
void addval(int **arr, int c1u, int c2u, int c3u, int c4u, int c1d, int c2d, int c3d, int c4d, int r1l, int r2l, int r3l, int r4l, int r1r, int r2r, int r3r, int r4r);
void randomise(int **arr);
void test_v(int **arr, int index);

/* Mallocar Change*/
int	**grid()
{
	int	i;
	int	j; 
	int	count;
    int**	arr;

	i=0;
	arr = (int**)malloc(6*sizeof(int*));
	while(i<6)
	{
		arr[i] = (int*)malloc(6 * sizeof(int));
		i++;
	}
	return arr;
}


/* Vaciar Memoria*/
void clear(int **arr)
{	
	int i;	
	for ( i = 0; i < 6; i++)
        free(arr[i]);
    free(arr);	   
}

/* IMPRIMIR Change*/
void print(int **arr)
{
	int i,j;
	char val;
	char nl = '\n';
	char sp = ' ';
	for (i = 0; i < 6; i++)
	{
        for (j = 0; j < 6; j++)
		{
           val =  arr[i][j] + '0';
		   write(1, &val, 1);
		   write(1, &sp, 1);
		}
		write(1, &nl, 1);
	}
	write(1, &nl, 1);
}

/* Girar  Change */
void turn(int **arr)
{
	int i,j;
	int arrcopy[6][6];
    for (i = 0; i < 6; i++)
	{
       	for (j = 0; j < 6; j++)
		{
			arrcopy[j][5-i] = arr[i][j];
		}
	}
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++)
		{
			arr[i][j]=arrcopy[i][j];
		}
	}
}


/*TEST WHOLE SQUAR*/
void test_a(int **arr)
{
	int index;
	int rotate;

	rotate = 4;
	while(rotate != 0 )
	{
		index = 1;
		while(index != 5)
		{
			test_v(arr, index);
			index++;
		}
	rotate--;
	}
}

/*Comprobar V*/
void test_v(int **arr, int index)
{
    count 
	int countg, big, countf,line;
	countg = arr[0][index];
	big = arr[1][index];
	countf = 1;
	line = 2;
	while(line < 5)
	{
		if(arr[line][index] > big)
		{
		big = arr[line][index];
		countf += 1;
		}
    line ++;
	}
	if (countf==countg)
	{
		printf("valid \n");
	}
	else
	{
        return;
	}
}

/*Add Values*/
void addval(int **arr, int c1u, int c2u, int c3u, int c4u, int c1d, int c2d, int c3d, int c4d, int r1l, int r2l, int r3l, int r4l, int r1r, int r2r, int r3r, int r4r)
{
 	arr[0][1] = c1u;
	arr[0][2] = c2u;
	arr[0][3] = c3u;
	arr[0][4] = c4u;
	
	arr[5][1] = c1d;
	arr[5][2] = c2d;
	arr[5][3] = c3d;
	arr[5][4] = c4d;

	arr[1][0] = r1l;
	arr[2][0] = r2l;
	arr[3][0] = r3l;
	arr[4][0] = r4l;

	arr[1][5] = r1r;
	arr[2][5] = r2r;
	arr[3][5] = r3r;
	arr[4][5] = r4r;
}


/* MAIN */
int main()
{
	int ** arr;
	int count = 0;
	printf("0");
	arr = grid();
	addval(arr, 4,3,2,1,1,2,2,2,4,3,2,1,1,2,2,2);
	printf("1");
	test_a(arr);
	return (0);
}
