/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 19:19:55 by mwisniew          #+#    #+#             */
/*   Updated: 2026/07/31 21:35:13 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
void	small_input(t_stack *a, t_stack *b)
{
	int	n;
	int	to_find;

	n = a->size;
	if (n == 1)
		return ;
	if (n == 2)
	{
		if (a->tail->val > a->head->val)
			write(1, "ra\n", 3);
		return ;
	}
	while (a->tail->val != 1 &&  a->tail->val != 2)
	{
		write(1, "ra\n", 3);
		rotate_stack(a);
	}
	if (a->tail->val == 1)
		to_find = 2;
	else
		to_find = 1;
	write(1, "pb\n", 3);
	push_stack_b(a, b);
	while (a->tail->val != to_find)
	{
		write(1, "ra\n", 3);
		rotate_stack(a);
	}
	write(1, "pb\n", 3);
	push_stack_b(a, b);
	if (b->tail->val < b->head->val)
	{
		write(1, "rb\n", 3);
		rotate_stack(b);
	}
}
