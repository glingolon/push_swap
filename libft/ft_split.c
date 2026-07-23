/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:55:58 by mwisniew          #+#    #+#             */
/*   Updated: 2026/06/29 18:29:24 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	res;
	size_t	i;

	res = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (!i || s[i - 1] == c))
			res++;
		i++;
	}
	return (res);
}

static size_t	ft_end_of_word(char const *s, int start, char c)
{
	size_t	i;

	i = start;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static void	*ft_clear_arr(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	i;
	size_t	words_idx;

	if (!s)
		return (NULL);
	words = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!words)
		return (NULL);
	i = 0;
	words_idx = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		words[words_idx++] = ft_substr(s, i, ft_end_of_word(s, i, c) - i);
		if (!words[words_idx - 1])
			return (ft_clear_arr(words, words_idx));
		i = ft_end_of_word(s, i, c);
	}
	words[words_idx] = NULL;
	return (words);
}
/*
#include <stdio.h>
int main(int argc, char *argv[])
{
	if (argc != 3) return 0;
	char **words = ft_split(argv[1], argv[2][0]);
	while (*words)
	{
		printf("%s\n", *words);
		words++;
	}
}
*/
