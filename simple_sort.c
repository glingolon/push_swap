/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 23:16:48 by mwisniew          #+#    #+#             */
/*   Updated: 2026/07/31 21:42:16 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	simple_sort(t_stack *a, t_stack *b)
{
	int	n;
	int	target;

	n = a->size;
	target = 1;
	while (target <= n)
	{
		while (a->tail->val != target)
		{
			write(1, "ra\n", 3);
			rotate_stack(a);
		}
		write(1, "pb\n", 3);
		push_stack_b(a, b);
		target++;
	}
	while (n--)
	{
		write(1, "pa\n", 3);
		push_stack_a(a, b);
	}
	return ;
}
