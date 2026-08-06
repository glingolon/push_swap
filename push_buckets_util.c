/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_buckets_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 13:33:30 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/05 21:30:13 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_max_bucket(int *bucket, int n)
{
	int	i;
	int	res;

	res = 0;
	i = 1;
	while (i <= n)
	{
		if (bucket[i] > res)
			res = bucket[i];
		i++;
	}
	return (res);
}

int	to_find(int *bucket, int left, int right, int n)
{
	int	i;
	int	res;

	i = 1;
	res = 0;
	while (i <= n)
	{
		if (bucket[i] == left || bucket[i] == right)
			res++;
		i++;
	}
	return (res);
}
