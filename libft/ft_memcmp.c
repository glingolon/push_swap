/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:54:55 by mwisniew          #+#    #+#             */
/*   Updated: 2026/06/29 17:54:57 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_handle_nulls(const void *s1, const void *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-((unsigned char *) s2)[0]);
	return (((unsigned char *) s1)[0]);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		res;
	size_t	i;

	if (n == 0)
		return (0);
	if (!s1 || !s2)
		return (ft_handle_nulls(s1, s2));
	i = 0;
	while (i < n)
	{
		res = ((unsigned char *) s1)[i] - ((unsigned char *) s2)[i];
		if (res != 0)
			return (res);
		i++;
	}
	return (0);
}
