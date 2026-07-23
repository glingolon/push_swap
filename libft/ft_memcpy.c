/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:55:04 by mwisniew          #+#    #+#             */
/*   Updated: 2026/07/16 13:46:29 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dest)
		return (dest);
	i = 0;
	while (i < n)
	{
		((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dest);
}
/*

int main()
{
	char dest[100] = "salk;djfskla;jf;lksa";
	char src[100] = "XXXXXXX";
	char dest2[100] = "salk;djfskla;jf;lksa";
	char src2[100] = "XXXXXXX";

	printf("%s - %s",(char *)  memcpy(dest, src, 7), 
	(char *)ft_memcpy(dest2, src2, 7));
}
*/
