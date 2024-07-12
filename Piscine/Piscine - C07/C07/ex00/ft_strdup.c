/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:51:44 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/02/29 21:01:57 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strdup(char *src);
{
	// get string length;
	// malloc that length to dest
	// iterate through index at src and copy to dest
	// add null character at the end f dest
	// return dest

}


//Verify Main
//////////////////////////////////////////////////////
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int main(void)
{
    const char *s1 = "String";
    char *s2 = ft_strdup(s1);
    assert(strcmp(s1, s2) == 0);
    free(s2);
}
//////////////////////////////////////////////////////
