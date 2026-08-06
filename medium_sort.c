/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 11:40:22 by mwisniew          #+#    #+#             */
/*   Updated: 2026/07/31 21:48:28 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	sqrt_ceil(int x)
{
	int	i;

	i = 0;
	while (i * i < x)
		i++;
	return (i);
}

int	in_block(int x, int i, int block_size)
{
	if (block_size * (i - 1) < x && block_size * i >= x)
		return (1);
	return (0);
}

void	pseudo_sort(t_stack *a, t_stack *b, int n)
{
	int			block_size;
	int			cur_block;

	cur_block = 1;
	block_size = sqrt_ceil(n);
	while (cur_block <= block_size)
	{
		while (a->size && a->size != n - block_size * cur_block)
		{
			if (in_block(a->tail->val, cur_block, block_size))
			{
				write(1, "pb\n", 3);
				push_stack_b(a, b);
			}
			else
			{
				write(1, "ra\n", 3);
				rotate_stack(a);
			}
		}
		cur_block++;
	}
}

void	final_sweep(t_stack *a, t_stack *b, int n)
{
	int	target;
	int	rotated;

	target = n;
	rotated = 0;
	while (target)
	{
		while (b->tail->val != target)
		{
			write(1, "rb\n", 3);
			rotate_stack(b);
			rotated++;
		}
		write(1, "pa\n", 3);
		push_stack_a(a, b);
		target--;
		while (rotated)
		{
			write(1, "rrb\n", 4);
			rev_rotate_stack(b);
			rotated--;
		}
	}
}

void	medium_sort(t_stack *a, t_stack *b)
{
	pseudo_sort(a, b, a->size);
	final_sweep(a, b, b->size);
}
