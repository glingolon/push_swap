/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 00:08:45 by mwisniew          #+#    #+#             */
/*   Updated: 2026/07/28 00:11:50 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap_stack(t_stack *st)
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
