/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:53:22 by mwisniew          #+#    #+#             */
/*   Updated: 2026/06/29 17:53:24 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
	{
		((unsigned char *) s)[i] = 0;
		i++;
	}
}
/*

int main()
{
	char	s[100] = "dobry wieczor";
	char	S[100] = "dobry wieczor";
	int		x[6] = {1, 2, 3, 4, 5, 6};
	int		X[6] = {1, 2, 3, 4, 5, 6};

	bzero(s, 30);
	ft_bzero(S, 30);
	
	bzero(x, 6);
	ft_bzero(X, 6);

	printf("%s - %s\n", s, S);
	for(int i = 0; i < 6; i++){
		if(x[i] != X[i]) printf("oops");
	}
}
*/
