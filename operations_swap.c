/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:27:21 by mwisniew          #+#    #+#             */
/*   Updated: 2026/07/25 20:18:41 by nfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap_stack(t_stack* st) //one jeszcze musza printowac ze sie wykonuja???
{
	int	temp;

	if (st->size < 2)
		return ;
	temp = st->tail->prev->val;
	st->tail->prev->val = st->tail->val;
	st->tail->val = temp;
}
void	swap_stacks(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
}
void	push_stack_a(t_stack *a, t_stack *b)
{
	t_element		*new;

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
	t_element		*new;

	if (a->size == 0)
		return ;
	new = malloc(sizeof(t_element));
	if (!new)
		return ;
	new->val = a->tail->val;
	add_back(b, new);
	remove_back(a);
}

void	rotate_stack(t_stack *st)
{
	t_element	*temp;

	temp = st->head;
	st->head = st->head->next;
	st->head->prev = NULL;
	st->tail->next = temp;
	temp->prev = st->tail;
	temp->next = NULL;
	st->tail = temp;		
}
void	rotate_stacks(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
}

void	rev_rotate_stack(t_stack *st)
{
	t_element	*temp;

	temp = malloc(sizeof(t_element));
	if (!temp)
		return ;
	temp->val = st->tail->val;
	add_front(st, temp);
	remove_back(st);
}

void	rev_rotate_stacks(t_stack *a, t_stack *b)
{
	rev_rotate_stack(a);
	rev_rotate_stack(b);
}
