/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 01:23:16 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/04 23:55:31 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	set_num(int *arr, int n, int num)
{
	int	i;

	i = 0;
	while (i < n)
		arr[i++] = num;
}

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	*fill_lis_endings(int *arr, int n)
{
	int	*lis_ending;
	int	i;
	int	j;
	int	max_so_far;

	lis_ending = malloc (n * sizeof(int));
	set_num(lis_ending, n, 1);
	i = 0;
	while (i < n)
	{
		j = 0;
		max_so_far = 0;
		while (j < i)
		{
			if (arr[j] < arr[i])
				max_so_far = max(max_so_far, lis_ending[j]);
			j++;
		}
		lis_ending[i] = max_so_far + 1;
		i++;
	}
	return (lis_ending);
}

static int	idx_of_min_ending(int *arr, int *lis_ending, int val, int n)
{
	int	i;
	int	cur_min;
	int	cur_min_idx;

	i = 0;
	cur_min = (int) 1e9;
	cur_min_idx = -1;
	while (i < n)
	{
		if (lis_ending[i] == val && arr[i] < cur_min)
		{
			cur_min = arr[i];
			cur_min_idx = i;
		}
		i++;
	}
	return (cur_min_idx);
}

int	*fill_in_lis(int *arr, int n)
{
	int	*lis_ending;
	int	*in_lis;
	int	i;
	int	lis_len;
	int	last_idx;

	in_lis = malloc ((n + 1) * sizeof(int));
	lis_ending = fill_lis_endings(arr, n);
	set_num(in_lis, n + 1, 0);
	lis_len = 0;
	i = 0;
	last_idx = n;
	while (i < n)
		lis_len = max(lis_len, lis_ending[i++]);
	while (lis_len)
	{
		last_idx = idx_of_min_ending(arr, lis_ending, lis_len--, last_idx);
		in_lis[arr[last_idx]] = 1;
	}
	free(lis_ending);
	return (in_lis);
}
/*
#include <stdlib.h>
int main(int argc, char *argv[]){
	
	int n = argc - 1;
	int *arr;
	if (n == 1)
	{
		char	**splat;
		splat = ft_split(argv[1], ' ');
		n = 0;
		for(int i = 0; splat[i]; i++) n++;
		arr = malloc ((n + 1) * sizeof(int));
		for(int i = 0; i < n; i++)
			arr[i] = atoi(splat[i]);
	}
	else
	{
		arr = malloc ((n + 1) * sizeof(int));
		int i = 0;
		while (i < n)
		{
			arr[i] = ft_atoi(argv[i + 1]);
			i++;
		}
	}

	int *lis = fill_in_lis(arr, n);
	for(int i = 0; i < n; i++)
	{
		if (lis[arr[i]]) printf("%d ", arr[i]);
	}
}
*/
