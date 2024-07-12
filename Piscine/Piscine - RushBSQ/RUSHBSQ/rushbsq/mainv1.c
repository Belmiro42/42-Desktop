/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dostuff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:55:57 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/28 10:40:57 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//Do Stuff
	// Open Map **************************************************
	// Get Information   *****************************************
	// MALLOC Convert Map To Array of Arrays *********************
	// Valid Maps 
		// 1		 *****************+++++++++******************+
		// 2		 ^**************************++++++++++++++****
		// 3		 *******++++++++++++++++++++******************
		// 4  		 ********************+*+++++++++**********++++
		// 5		 *********************************************
		// 6         *********************************************
	// Find Square    
	// Write Square   ********************************************
	// Display Square ********************************************
	// FREE Malloc Space *****************************************

//////////////////////////////////////////////////////////////////////////////////
//                                  finddddddd                                  //
//////////////////////////////////////////////////////////////////////////////////

char f(char *ptr, int *step, int *x, int *y)
{
    return (ptr[(*step)*(*y) + *x]);
}

//////////////////////////////////////////////////////////////////////////////////
//                                  error_8                                     //
//////////////////////////////////////////////////////////////////////////////////

//
void error8(char *str, int start, int step_numb, int step, int *error)
{
	int i;
	char ch;

	i=0;
	while (step_numb != 0)
	{
		if (str[i+step-1] != '\n') *error = 1;
		ch = str[i+step -1];
		write (1, &ch, 1);
		i += step; 	
		step_numb--;
	}
}

//////////////////////////////////////////////////////////////////////////////////
//                                  error_7                                     //
//////////////////////////////////////////////////////////////////////////////////

//Good
void error7(int *step_numb, int *step, int *error)
{
	if (*step_numb < 1 || *step < 2) *error = 1;
}

//////////////////////////////////////////////////////////////////////////////////
//              		error6 contained in error8 								//
//              			anyways error message	                            //
//////////////////////////////////////////////////////////////////////////////////

void error_message()
{
	char *mess;
	char ch;

	mess = "map error";
	while (*mess)
	{
		ch = *mess;
		write(1, &ch, 1);
		mess++;
	}
}

//////////////////////////////////////////////////////////////////////////////////
//                                  error_5                                     //
//////////////////////////////////////////////////////////////////////////////////

void error5(char *str, int *step, int *step_numb, char *obs, char *empty, int *error)
{
	int y;
	int x;

	y=0;
	while (y < *step_numb)
	{
		x=0;
		while (x < *step)
		{
			// Exception para \n
			if (f(str, step, &x, &y) != *obs && f(str, step, &x, &y) != *empty) *error = 1;		
			x++;
		}
		y++;
	}
}

//////////////////////////////////////////////////////////////////////////////////
//                                  error_4                                     //
//////////////////////////////////////////////////////////////////////////////////

void error4(int *start, int *step_count, int *error)
{
	int count;
	int scount;

	count = 0;
	scount = *step_count;
	//Algo mal con esto que no passa el numero de digitos bien para n > 10
	while (scount != 0)
	{
		scount = scount/10;
		count ++;
	}
	if (*start != (count + 3)) *error = 1;	
}

//////////////////////////////////////////////////////////////////////////////////
//                                  error_3                                     //
//////////////////////////////////////////////////////////////////////////////////


// NI TENGO IDEA
void error3(char *obs, char *empty, char *fill, int *error)
{
	if (*empty < 32 || *empty == 127) *error = 1;
	if (*obs < 32 || *obs == 127) *error = 1;
	if (*fill < 32 || *fill == 127) *error = 1;
}

//////////////////////////////////////////////////////////////////////////////////
//                                error_todos                                   //
//////////////////////////////////////////////////////////////////////////////////

int error(char *str, char *empty, char *obs, char *fill, int *start, int *step, int *step_numb)
{
	int error;
	
	error = 0;
	//error8(str, *start, *step_numb, *step, &error);
	//error7(step_numb, step, &error);
	//error5(str, step, step_numb, obs, empty, &error);
	//error4(start, step_numb, &error);
	//error3(obs, empty, fill, &error);
	return(error);
}

//////////////////////////////////////////////////////////////////////////////////
//                                  DISPLAY                                     //
//////////////////////////////////////////////////////////////////////////////////

void display(char *str, int *step, int *step_numb, int *tam_g, int *x_g, int *y_g, char *fill)
{
	char ch;
	int y;
	int x;

	y = 0;
	while (y < *step_numb)
	{
		x = 0;
		while (x < *step)
		{
            /*
			if(*y_g <= y && y < (*y_g + *tam_g)  && *x_g <= x &&  x < (*x_g + *tam_g) && f(str, step, &x, &y) != '\n')
				{
					ch = *fill;
					write(1, &ch, 1);
				}
			else
				{
             */
					ch = f(str, step, &x, &y);
					write(1, &ch, 1);
				//}
			x++;
		}
		y++;
	}
}

//////////////////////////////////////////////////////////////////////////////////
//                                  assign	                                    //
//////////////////////////////////////////////////////////////////////////////////

void assign(int *x, int *x_g, int *y, int *y_g, int *tam_g, int *tam)
{
    *x_g = *x;
	*y_g = *y;
	*tam_g = *tam;
}

//////////////////////////////////////////////////////////////////////////////////
//                                 intermediate                                 //
//////////////////////////////////////////////////////////////////////////////////

void intermediate(int *vacio, int *x, int *y, char *str, int *step, char *obs, int *count, int *step_numb)
{
    int count_x;
    int count_y;
    int current_y;
    int current_x;
    
    
    count_y = 0;
    while (count_y <= *count)
    {
        if ((count_y + *y) == *step_numb) *vacio = 0;
        count_x = 0;
        while (count_x <= *count)
        {
            if ((count_x + *x) == *step) *vacio = 0;
            current_x = *x + count_x;
            current_y = *y + count_y;
            if (f(str, step, &current_x, &current_y) == *obs) *vacio = 0;
            count_x++;
        }
        count_y++;
    }
}

//////////////////////////////////////////////////////////////////////////////////
//                                  check_squares                               //
//////////////////////////////////////////////////////////////////////////////////

void check_squares(char *str, int *x, int *y, int *x_g, int *y_g, int *tam_g, int *step, char *obs, int *step_numb)
{
	int vacio;
	int count;
	int tam;

	vacio = 1;
	count = 0;
	while (vacio == 1)
	{ 
		intermediate(&vacio, x, y, str, step, obs, &count, step_numb);
		if (vacio == 1) tam = (count + 1);
		count++;
    }
    /*
    printf("tam: %d \n", tam);
    printf("x: %d \n", *x);
    printf("y: %d \n", *y);
    printf("tam_g: %d \n", *tam_g);
    printf("xg: %d \n", *x_g);
    printf("yg: %d \n", *y_g);
     */
	if (tam > *tam_g) assign(x, x_g, y, y_g, tam_g, &tam);
    
}

//////////////////////////////////////////////////////////////////////////////////
//                                  find_squares                                //
//////////////////////////////////////////////////////////////////////////////////

void find_square(char *str, int *step, int *start, char *obs, char *empty, char *fill, int *step_numb)
{
	int x;
	int y;
	int tam_g;
	int x_g;
	int y_g;
	char ch;

	y = 0;
	x_g = 0;
	y_g = 0;
	tam_g = 0;
	while (y < *step_numb)
	{
		x=0;
		while (x < *step)
		{
			check_squares(str, &x, &y, &x_g, &y_g, &tam_g, step, obs, step_numb);	 			
			x++;
		}
		y++;
	}
	display(str, step, step_numb, &tam_g, &x_g, &y_g, fill);
}

//////////////////////////////////////////////////////////////////////////////////
//                                  step_num                                    //
//////////////////////////////////////////////////////////////////////////////////
int step_num(char *ptr)
{
	int count;
	int indice;

	count = 0;
	indice = 0;

	while(ptr[indice] != '\0')
	{
		if (ptr[indice] == '\n') count++;
		indice++;
	}
	return (count);
}

//////////////////////////////////////////////////////////////////////////////////
//                                	get_ll			                            //
//////////////////////////////////////////////////////////////////////////////////

int get_ll(char *ptr, int cont)
{
	int i;
	int count;
	int c;

	c = 0;
	i = 0;
	count = 0;
	while(c != (cont))
	{
		if (ptr[i] == '\n') c++;
		if (c == (cont - 1)) count++;
		i++;
	}
	return(count + 1);
}

//////////////////////////////////////////////////////////////////////////////////
//									get_char									//
//////////////////////////////////////////////////////////////////////////////////

char get_char(char *ptr, int n)
{
	int i;
	
	i=0;
	while (ptr[i] != '\n')
	{
		i++;
	}
	return (ptr[i + n]); 
}

//////////////////////////////////////////////////////////////////////////////////
//									file_read									//
//////////////////////////////////////////////////////////////////////////////////

char *file_read(char *filename)
{
	FILE *file;
	char *buffer;

	file = fopen(filename, "r");
	buffer = (char *)malloc(1000000 * sizeof(char));//Enough memory for the fil
	fread(buffer, 1000000, 1, file); // Read in the entire file
	fclose(file);
	return(buffer);
}

//////////////////////////////////////////////////////////////////////////////////
// 									DO_STUFF									//
//////////////////////////////////////////////////////////////////////////////////

void do_stuff(char *filename)
{	
	char *ptr;
	char empty;
	char obs;
	char fill;
	int step;
	int start;
	int step_numb;
	int not_error;
	
	ptr = file_read(filename);
	empty = get_char(ptr, -3);
	obs = get_char(ptr, -2);
	fill = get_char(ptr, -1);
	start = get_ll(ptr, 1);
	step = get_ll(ptr, 2);
	step_numb = step_num(ptr) - 1;
	ptr += (start);
	not_error = error(ptr, &empty, &obs, &fill, &start, &step, &step_numb);
	(not_error == 0) ? find_square(ptr, &step, &start, &obs, &empty, &fill, &step_numb) : (error_message());
	ptr -= (start);
	free(ptr);
}

//////////////////////////////////////////////////////////////////////////////////
//                       				MAIN									//
//////////////////////////////////////////////////////////////////////////////////

int main(int argn, char **argv)  
{
	int count;

	count = 1;
	while (argn-1 >= count)
	{
		do_stuff(argv[count]);
		if ((argn - 1) != count)
		{
			write(1, "\n", 1);
		}
		count++;	
	}
	return (0);
}
