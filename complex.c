/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 19:48:27 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/05 21:16:19 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

int	*fill_buckets(int *in_lis, int bucket_size, int n)
{
	int	count;
	int	current_bucket;
	int	i;
	int	*bucket;

	bucket = ft_calloc(sizeof(int), n + 1);
	i = 1;
	count = 0;
	current_bucket = 1;
	while (i <= n)
	{
		if (!in_lis[i])
		{
			bucket[i] = current_bucket;
			count++;
			if (count >= bucket_size)
			{
				count = 0;
				current_bucket++;
			}
		}
		i++;
	}
	return (bucket);
}

void	complex_sort(t_stack *a, t_stack *b, int *arr)
{
	int	*in_lis;
	int	*bucket;

	in_lis = fill_in_lis(arr, a->size);
	bucket = fill_buckets(in_lis, 4, a->size);
	push_buckets_to_b(a, b, bucket, a->size);
	//for(int i = 1; i <= a->size; i++) printf("i: %d - bucket: %d\n", i, bucket[i]);
}
