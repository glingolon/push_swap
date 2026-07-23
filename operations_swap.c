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
	t_element	temp;

	if (st->size < 2)
		return ;
	temp = *(st->tail->prev);
	*(st->tail->prev) = *(st->tail);
	*(st->tail) = temp;
}
/*
void	swap_stacks(t_stack *a, t_stack *b);
{
	swap_stack(&a);
	swap_stack(&b);
}

void	push_stack(t_stack *a, t_stack *b)
{
	
}
*/
