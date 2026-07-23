/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:55:09 by mwisniew          #+#    #+#             */
/*   Updated: 2026/06/29 17:55:09 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *) s)[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
/*
int main(){
	char *s = malloc(100);
	s = (char *) ft_memset(s, 'h', 20);
	//printf("%s", s);
	for(int i = 0; i < 20; i++){
		if (s[i] == 0) printf("N");
		else printf("%c", s[i]);
	}
}
*/
