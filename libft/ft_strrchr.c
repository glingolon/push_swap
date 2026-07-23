/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:56:54 by mwisniew          #+#    #+#             */
/*   Updated: 2026/06/29 17:56:55 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	if (!s)
		return (NULL);
	res = NULL;
	while (*s)
	{
		if (*s == (char) c)
			res = (char *) s;
		s++;
	}
	if (*s == (char) c)
		return ((char *) s);
	return (res);
}
/*
int main(int argc, char *argv[]){
	if(argc != 3) return 0;
	int i = 0;
	char to_find = argv[2][0];
	int idx = -1;
	if (ft_strrchr(argv[1], to_find) == NULL){
		printf("NULL");
		return 0;
	}
	while(argv[1][i]){
		if(argv[1][i] == *(ft_strrchr(argv[1], to_find)))
				idx = i;
		i++;
	}
	if(argv[1][i] == *(strrchr(argv[1], to_find))) idx = i;
	printf("%d", idx);
}
*/
