/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 22:39:27 by mwisniew          #+#    #+#             */
/*   Updated: 2026/07/23 15:03:33 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	*sorted_copy(int *arr, int n)
{
	int	i;
	int	j;
	int	*res;

	res = malloc (sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		res[i] = arr[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (res[i] > res[j])
				swap(&res[i], &res[j]);
			j++;
		}
		i++;
	}
	return (res);
}

void	compress(int *arr, int n)
{
	int	i;
	int	j;
	int	cur;
	int	*sorted_arr;

	sorted_arr = sorted_copy(arr, n);
	i = 0;
	cur = 1;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (sorted_arr[i] == arr[j])
				arr[j] = cur;
			j++;
		}
		if (i != n - 1 && sorted_arr[i] != sorted_arr[i + 1])
			cur++;
		i++;
	}
	free(sorted_arr);
}
