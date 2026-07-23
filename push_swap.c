/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 22:43:17 by mwisniew          #+#    #+#             */
/*   Updated: 2026/07/22 20:34:43 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	i;
	int	n;
	int	*arr;

	n = argc - 1;
	arr = malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	compress(arr, n);
	i = 0;
	while (i < n)
	{
		ft_putnbr_fd(arr[i], 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	free(arr);
}
