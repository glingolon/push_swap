/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 22:43:17 by mwisniew          #+#    #+#             */
/*   Updated: 2026/07/30 17:37:03 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>
int	main(int argc, char *argv[])
{
	int				i;
	int				n;
	t_element		*new_element;
	t_stack			a;
	t_stack			b;
	static t_input input;

	init_stack(&a);
	init_stack(&b);
	fill_input(&input, argc, argv);

	printf("mode: %d\nbench: %d\n", input.algorithm_complexity, input.bench);
	//fill_stack(a);
	//fill_stack(b);

	/*
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
		new_element = malloc(sizeof(t_element));
		new_element->val = arr[i];
		add_back(&a, new_element);
		i++;
	}
	simple_sort(&a, &b);
	free(arr);
	*/
}
