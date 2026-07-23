/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:55:16 by mwisniew          #+#    #+#             */
/*   Updated: 2026/06/29 17:55:17 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	if (!n)
		return (dest);
	if (dest < src)
	{
		while (i < n)
		{
			((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
			i++;
		}
		return (dest);
	}
	i = n - 1;
	while (1)
	{
		((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
		if (i == 0)
			break ;
		i--;
	}
	return (dest);
}
/*
int main()
{
	char s[1000];
	for(int i = 0; i < 1000; i++) s[i] = 0;
	s[0] = 'm';
	s[1] = 'e';
	s[2] = 'o';
	s[3] = 'w';
	s[4] = 'a';
	s[5] = 'b';
	s[6] = 'c';

    char *dest = s;
    char *src = dest + 2;
    printf("%s",(char *) ft_memmove(dest, src, 7));
    printf("%c, %c", s[5], s[6]);
	//(char *) memmove(dest2, src2, 7));
}
*/
