/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:56:44 by mwisniew          #+#    #+#             */
/*   Updated: 2026/06/29 17:56:45 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_handle_nulls(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-s2[0]);
	return (s1[0]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int			res;
	size_t		i;

	if (n == 0)
		return (0);
	if (!s1 || !s2)
		return (ft_handle_nulls(s1, s2));
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		res = (unsigned char) s1[i] - (unsigned char) s2[i];
		if (res != 0)
			return (res);
		i++;
	}
	return (0);
}
/*
int main(){
	char s1[] = "ABC", s2[] = "ABC";
	printf("[%s, %s]: %d - %d\n",
       	s1, s2, ft_strncmp(s1, s2, 2), strncmp(s1, s2, 2));

	char s3[] = "ABC", s4[] = "AB";
	printf("[%s, %s]: %d - %d\n",
       	s3, s4, ft_strncmp(s3, s4, 3), strncmp(s3, s4, 3));
	
	char s5[] = "ABA", s6[] = "ABZ";
	printf("[%s, %s]: %d - %d\n",
       	s5, s6, ft_strncmp(s5, s6, -1), strncmp(s5, s6, -1));
	
	char s7[] = "ABJ", s8[] = "ABC";
	printf("[%s, %s]: %d - %d\n",
       	s7, s8, ft_strncmp(s7, s8, 3), strncmp(s7, s8, 3));
}
*/
