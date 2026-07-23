/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 17:53:28 by mwisniew          #+#    #+#             */
/*   Updated: 2026/06/29 17:53:29 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	mult;
	void	*res;

	if (!nmemb || !size)
		return (malloc(1));
	mult = nmemb * size;
	if (mult / nmemb != size)
		return (NULL);
	res = malloc(mult);
	if (res)
		ft_bzero(res, mult);
	return (res);
}
