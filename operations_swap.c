/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:27:21 by mwisniew          #+#    #+#             */
/*   Updated: 2026/07/23 18:37:49 by nfil             ###   ########.fr       */
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
	t_element	new;
	t_element	temp;

	if (a->size == 0)
		return ;
	new.val = b->tail->val;
	new.next = a->tail;
	new.prev = NULL;
	a->tail = &new;
	temp = *(b->tail);
	b->tail = b->tail->next;
	b->tail->prev = NULL;
//	free(temp);
			
}	
void	push_stack_b(t_stack *a, t_stack *b)
{
	t_element	new;
	t_element	temp;

	if (b->size == 0)
		return ;
	new.val = a->tail->val;
	new.next = (b->tail);
	new.prev = NULL;
	b->tail = &new;
	temp = *(a->tail);
	a->tail = a->tail->next;
	a->tail->prev = NULL;
//	free(temp);		
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
//	free(temp);		
}
