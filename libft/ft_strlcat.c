/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:56:25 by mwisniew          #+#    #+#             */
/*   Updated: 2026/06/29 17:56:25 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (!dest || !src)
		return (src_len + dest_len);
	if (dest_len >= size)
		return (size + src_len);
	i = 0;
	while (dest_len + i < size - 1 && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*
int	main(void)
{
	char	dest[10] = "hello";
	char	src[10] = "world";
	int	size = 10;

	printf("before: %s\n", dest);
	printf("strlcat: %ld\n", ft_strlcat(dest, src, size));
	printf("after: %s\n", dest);
} 
*/
