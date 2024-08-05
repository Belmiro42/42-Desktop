/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:05:16 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/08/05 02:19:03 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// TODO: TODO: UNTESTED

/*
//DESCRIPTION: SYNOPSIS
//cd [-L|-P] [directory]
//
//NOTE: No flags operates as -L which includes step 8 and 9
//
//DESCRIPTION: DESCRIPTION

//1. If no directory operand is given and the HOME environment variable is empty
//or undefined, the default behavior is implementation-defined and no further
//steps shall be taken.

if (ft_arrlen(args) == 1)
//GO HOME
if (strchr(getenv(HOME), '/') == NULL)

//2. If no directory operand is given and the HOME environment variable is set to
//a non-empty value, the cd utility shall behave as if the directory named in the
//HOME environment variable was specified as the directory operand.

else
{
tmp = get_val_env("PWD");
new_val_env("OLDPWD", tmp);
new_val_env()
chdir(getenv(HOME))
//TODO: 	Figure out how to do this but figure out if you need to change OLDPWD to
//		PWD and if you need to change the pwd variable. Check what chdir does
}


//3. If the directory operand begins with a <slash> character, set curpath to the
//operand and proceed to step 7.

//NOTE: If directory is an empty string, the results are unspecified.
//-  When a <hyphen-minus> is used as the operand, this shall be equivalent to:
//	cd "$OLDPWD" && pwd


NOTE: if arg[2][0] = '-'
NOTE:		{
NOTE:			export()
//TODO: 	Figure out how to do this but figure out if you need to change OLDPWD to
//		PWD and if you need to change the pwd variable. Check what chdir does
NOTE:			chdir(getenv(OLDPWD)
NOTE:		}

NOTE: if arg[2][0] = '/'
NOTE:		seven = true

//4. If the first component of the directory operand is dot or dot-dot, proceed to
//step 6.

NOTE: if (arg[2][0] = '.' && seven == false)
NOTE: 		six = true

//5. Starting  with  the  first  pathname in the <colon>-separated pathnames of
//CDPATH (see the ENVIRONMENT VARIABLES section) if the pathname is non-null, test
//if the concatenation of that pathname, a <slash> character if that pathname did
//not end with a <slash> character, and the directory operand names a directory.
//If the pathname is null, test if the concatenation of dot, a <slash> character,
//and the operand names a directory. In either case, if the resulting string names
//an existing directory, set curpath to that string and proceed to step 7.
//Otherwise, repeat this step with the next pathname in CDPATH until all
//pathnames have been tested.

//6. Set curpath to the directory operand.

	//????

//7.If curpath does not begin with a <slash> character, set curpath to the string
//formed by the concatenation of the value of PWD, a <slash> character if the
//value of PWD did not end with a <slash> character, and curpath.

NOTE: 	if (curpath[0] != ''\')
NOTE: 	{
NOTE: 		char *cpy = PWD;
NOTE: 		while (*cpy)
NOTE: 			cpy++;
NOTE: 		if (*(--cpy) != '/')
NOTE: 			curpath = ft_strhoin("/", curpath, KEEP, DEL)
NOTE: 		curpath = ft_strjoin(getenv("PWD"), curpath, KEEP, DEL)
NOTE: 	}

//8. The curpath value shall then be converted to canonical form as follows,
//considering each component from beginning to end, in sequence:

//	a. Dot components and any <slash> characters that separate them from the
//	next component shall be deleted.

//	b. For each dot-dot component, if there is a preceding component and it is
//	neither root nor dot-dot, then:

//		i.  If the preceding component does not refer (in the context of		TODO: Also
//		pathname resolution with symbolic links followed) to a directory, then
//		the cd utility shall display an appropriate error message and  no
//		further  steps shall be taken.

NOTE: 	char *strcpy;
NOTE: 	strcpy = malloc(sizeof(char) * ft_strlen(curpath));
NOTE: 	int iterator;
NOTE: 	iterator = 0;
NOTE: 	int iterator_copy;
NOTE: 	iterator_copy = 0;
NOTE: 	while (curpath[iterator])
NOTE: 	{
NOTE: 	if (curpath[iterator] == '/' && curpath[iterator] == '.' && curpath[iterator] == '.')
NOTE: 	{
NOTE: 		check_path_valid();								TODO: Follow Symbolic Links Aswell
NOTE: 		iterator += 3;
NOTE: 	}
NOTE: 	else if (curpath[iterator] == '/' && curpath[iterator] == '.')
NOTE: 		iterator += 2;
NOTE: 	else if (curpath[iterator] == '/' && curpath[iterator] == '/')
NOTE: 		iterator += 1;
NOTE: 	else
NOTE: 		strcpy[iterator_copy++] = curpath[iterator++];
NOTE: 	}
NOTE: 	strcpy[iterator_copy] = curpath[iterator];
NOTE: 	free(curpath);
NOTE: 	curpath = strcpy;


//	c. An  implementation  may  further  simplify  curpath  by removing any			NOTE: DONE ABOVE
//	trailing <slash> characters that are not also leading <slash> characters,
//	replacing multiple non-leading consecutive <slash> characters with a single
//	<slash>, and replacing three or more leading <slash> characters with a
//	single <slash>.  If, as a result of this canonicalization, the curpath
//	variable is null, no further steps shall be taken.


//9. If curpath is longer than {PATH_MAX} bytes (including the terminating null) 			TODO: ?? IS NECESSSARY?
//and the directory operand was not longer than {PATH_MAX} bytes (including the			?? I reckon dont do this as we need to save value in pwd
//terminating null), then curpath shall be converted from an  absolute
//pathname  to  an  equivalent relative pathname if possible.

NOTE: 	chdir(curpath)
NOTE: 	export() //OLDPWD to be PWD
NOTE: 	export() //PWD to be curpath

//10. The cd utility shall then perform actions equivalent to the chdir() function		chdir(curpath)
//called with curpath as the path argument. If these actions fail for any reason,			export() //OLDPWD to be PWD
//the cd utility shall display an appropriate error message and the remainder of			export() //PWD to be curpath
//this step shall not be executed. If the -P option is not in effect, the PWD
//environment variable shall be set to the value that curpath had on entry to step
//9 (i.e., before conversion to a relative  pathname). If  the  -P option is in
//effect, the PWD environment variable shall be set to the string that would be
//output by pwd -P.  If there is insufficient permission on the new directory, or
// on any parent of that directory, to determine the current working directory,
// the value of the PWD environment variable is unspecified.

//If, during the execution of the above steps, the PWD environment variable is
//set, the OLDPWD environment variable shall also be set to the value of the old
//working directory (that is the current working  directory  immediately prior to
//the call to cd).
}
*/