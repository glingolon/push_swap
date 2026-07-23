/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:56:04 by mwisniew          #+#    #+#             */
/*   Updated: 2026/06/29 17:56:05 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if (*s == (char) c)
		return ((char *) s);
	return (NULL);
}
/*
int main(int argc, char *argv[]){
    if(argc != 3) return 0;
    int i = 0;
    char to_find = argv[2][0];
    if (ft_strchr(argv[1], to_find) == NULL){
        printf("NULL");
        return 0;
    }
    while(argv[1][i]){
        if(argv[1][i] == *(ft_strchr(argv[1], to_find))){
        	printf("%d", i);
			break;
		}
		i++;
    }
    if('\0'  == *(ft_strchr(argv[1], to_find)))
    	printf("%d", i);
}
*/
