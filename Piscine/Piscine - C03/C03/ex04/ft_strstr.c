/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmatos-d <bmatos-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 22:49:19 by bmatos-d          #+#    #+#             */
/*   Updated: 2024/04/13 22:53:37 by bmatos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	index_str;
	int	index_to_find;

	index_str = 0;
	while (str[index_str])
	{
		index_to_find = 0;
		while (to_find[index_to_find] == str[index_str + index_to_find])
		{
			if (to_find[index_to_find] == '\0')
				return (str + index_str);
			index_to_find ++;
		}
		index_str++;
	}
	return (0);
}
//
//#include <stdio.h>
//#include <string.h>
//
//int main() {
//    const char *haystack = "Hello, world!";
//    const char *needle = "wo¡rld";
//
//    char *result = strstr(haystack, needle);
//
//    if (result != NULL) {
//        printf("Substring found at index: %ld\n", result - haystack);
//    } else {
//        printf("Substring not found.\n");
//    }
//
//    return 0;
//}
//