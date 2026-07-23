/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:56:58 by mwisniew          #+#    #+#             */
/*   Updated: 2026/06/29 19:09:17 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	prefix;
	size_t	suffix;
	size_t	s1_len;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	if (s1_len == 0)
		return (ft_strdup(""));
	prefix = 0;
	while (s1[prefix] && ft_strchr(set, s1[prefix]))
		prefix++;
	suffix = s1_len - 1;
	while (suffix && ft_strchr(set, s1[suffix]))
		suffix--;
	return (ft_substr(s1, prefix, suffix - prefix + 1));
}
