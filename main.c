/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 22:43:17 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/05 15:02:39 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

void	print_stacks(t_stack *a, t_stack *b)
{
	int h = (a->size > b->size) ? a->size : b->size;
	t_element *cur_a = a->tail;
	t_element *cur_b = b->tail;

	for(int i = h; i; i--)
	{
		if (i <= a->size)
		{
			printf("  %d", cur_a->val);
			printf("\t");
			cur_a = cur_a->prev;
		}
		else printf(" \t");

		if (i <= b->size)
		{
			printf("  %d", cur_b->val);
			cur_b = cur_b->prev;
		}
		printf("\n");
	}
		printf("------------\n");
		printf("  A       B");
}

int	main(int argc, char *argv[])
{
	int				i;
	t_element		*new_element;
	t_stack			a;
	t_stack			b;
	static t_input input;

	init_stack(&a);
	init_stack(&b);
	fill_input(&input, argc, argv);
	
	//fill_stack(a);

	compress(input.init_arr, input.arr_len);
	i = 0;
	while (i < input.arr_len)
	{
		new_element = malloc(sizeof(t_element));
		new_element->val = input.init_arr[i];
		add_front(&a, new_element);
		i++;
	}
	//simple_sort(&a, &b);
	complex_sort(&a, &b, input.init_arr);
	print_stacks(&a, &b);
}
