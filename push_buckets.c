/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_buckets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:18:04 by mwisniew          #+#    #+#             */
/*   Updated: 2026/08/05 21:30:11 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	next_cheapest(t_stack *a, int *bucket, int left, int right)
{
	int			dist_from_top;
	int			dist_from_bot;
	t_element	*cur;

	dist_from_top = 0;
	dist_from_bot = 1;
	cur = a->tail;
	while (cur && bucket[cur->val] != left && bucket[cur->val] != right)
	{
		dist_from_top++;
		cur = cur->prev;
	}
	cur = a->head;
	while (cur && bucket[cur->val] != left && bucket[cur->val] != right)
	{
		dist_from_bot++;
		cur = cur->next;
	}
	if (dist_from_top < dist_from_bot)
		return (dist_from_top);
	return (-dist_from_bot);
}

static void	exec_moves(t_stack *a, t_stack *b, int moves)
{
	while (moves)
	{
		if (moves > 0)
		{
			rotate_stack(a);
			write(1, "ra\n", 3);
			moves--;
		}
		else
		{
			rev_rotate_stack(a);
			write(1, "rra\n", 4);
			moves++;
		}
	}
}

static void	push_and_rot(t_stack *a, t_stack *b, int *bucket, int left)
{
	push_stack_b(a, b);
	write(1, "pb\n", 3);
	if (bucket[b->tail->val] == left)
	{
		bucket[b->tail->val] = 0;
		write(1, "rb\n", 3);
		rotate_stack(b);
	}
	else
		bucket[b->tail->val] = 0;
}

void	push_buckets_to_b(t_stack *a, t_stack *b, int *bucket, int n)
{
	int	left_bucket;
	int	right_bucket;
	int	max_bucket;
	int	moves;
	int	nums_left;

	max_bucket = get_max_bucket(bucket, n);
	left_bucket = (max_bucket / 2) + max_bucket % 2;
	right_bucket = (max_bucket / 2) + 1;
	while (left_bucket > 0 && right_bucket <= max_bucket)
	{
		nums_left = to_find(bucket, left_bucket, right_bucket, n);
		while (nums_left--)
		{
			moves = next_cheapest(a, bucket, left_bucket, right_bucket);
			exec_moves(a, b, moves);
			push_and_rot(a, b, bucket, left_bucket);
		}
		left_bucket--;
		right_bucket++;
	}
}
