/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:56:28 by mwisniew          #+#    #+#             */
/*   Updated: 2026/06/29 17:56:29 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size_t_strlen(const char *s)
{
	unsigned int	l;

	l = 0;
	while (*s != '\0')
	{
		l++;
		s++;
	}
	return ((size_t) l);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	if (!dest || !src)
		return (0);
	i = 0;
	src_len = ft_size_t_strlen(src);
	if (size == 0)
		return (src_len);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
/*
int main(){
	char s[] = "it worked";
	char s2[] = "it didnt work :c";

	ft_strlcpy(s2, s, 17);
	printf("%s", s2);
}
*/
