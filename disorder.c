/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfil <nfil@student.42warsaw.pl>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 19:05:34 by nfil              #+#    #+#             */
/*   Updated: 2026/07/28 22:55:39 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

float	disorder_calc(int *a, int n)
{
	int		i;
	int		j;
	int		mistakes;

	mistakes = 0;
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (a[i] > a[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return (((float) mistakes) / (n * (n - 1) / 2));
}
/*
#include <stdio.h>
int	main()
{
	int	a[10] = {4, 60, 3, 87, 40};
	printf("%f", disorder_calc(a, 5));
}
*/
