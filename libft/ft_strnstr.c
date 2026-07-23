/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:56:49 by mwisniew          #+#    #+#             */
/*   Updated: 2026/06/29 17:56:50 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	if (!big || !little)
		return (0);
	if (little[0] == 0)
		return ((char *) big);
	i = 0;
	little_len = ft_strlen(little);
	while (i < len && big[i])
	{
		j = 0;
		while (i + j < len && big[i + j]
			&& little[j] && big[i + j] == little[j])
			j++;
		if (j == little_len)
			return ((char *) big + i);
		i++;
	}
	return (NULL);
}
/*
int main(int argc, char *argv[]){
	const char *big = "meowmeowhejmeow";
	const char *little = "hej";
	
	if (argc != 4){
		char *mine = ft_strnstr(big, little, 11);
		char *correct = strnstr(big, little, 11);
		printf("[%s]: %s\n", correct, mine);
		return 0;
	}
	char *mine = ft_strnstr(argv[1], argv[2], atoi(argv[3]));
	char *correct = strnstr(argv[1], argv[2], atoi(argv[3]));
	printf("[%s]: %s\n", correct, mine);
}
*/
