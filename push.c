/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 00:08:22 by mwisniew          #+#    #+#             */
/*   Updated: 2026/07/28 00:08:41 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push_stack_a(t_stack *a, t_stack *b)
{
	t_element	*new;

	if (b->size == 0)
		return ;
	new = malloc(sizeof(t_element));
	if (!new)
		return ;
	new->val = b->tail->val;
	add_back(a, new);
	remove_back(b);
}

void	push_stack_b(t_stack *a, t_stack *b)
{
	t_element	*new;

	if (a->size == 0)
		return ;
	new = malloc(sizeof(t_element));
	if (!new)
		return ;
	new->val = a->tail->val;
	add_back(b, new);
	remove_back(a);
}
