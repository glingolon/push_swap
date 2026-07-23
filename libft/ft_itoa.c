/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:53:58 by mwisniew          #+#    #+#             */
/*   Updated: 2026/06/29 17:53:59 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(int n)
{
	int	l;

	if (!n)
		return (1);
	l = 0;
	if (n < 0)
		l++;
	while (n)
	{
		l++;
		n /= 10;
	}
	return (l);
}

static char	*ft_zero_str(void)
{
	char	*res;

	res = malloc(2);
	res[0] = '0';
	res[1] = 0;
	return (res);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		l;
	long	x;

	x = n;
	if (!x)
		return (ft_zero_str());
	l = ft_int_len(x);
	s = malloc(l + 1);
	if (!s)
		return (NULL);
	if (x < 0)
	{
		x = -x;
		s[0] = '-';
	}
	s[l--] = '\0';
	while (x)
	{
		s[l--] = (x % 10) + 48;
		x /= 10;
	}
	return (s);
}
/*
#include <stdio.h>
int main(int argc, char *argv[])
{
	if(argc != 2) return 0;
	printf("%s", ft_itoa(atoi(argv[1])));
}
*/
