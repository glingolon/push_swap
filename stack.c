/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 17:25:20 by mwisniew          #+#    #+#             */
/*   Updated: 2026/07/23 14:59:56 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	add_back(t_stack *s, t_element *e)
{
	if (!s->size)
	{
		s->head = e;
		s->tail = e;
		e->next = NULL;
		e->prev = NULL;
		s->size = 1;
		return ;
	}
	s->tail->next = e;
	e->next = NULL;
	e->prev = s->tail;
	s->tail = e;
	s->size++;
}

void	add_front(t_stack *s, t_element *e)
{
	if (!s->size)
	{
		s->head = e;
		s->tail = e;
		e->next = NULL;
		e->prev = NULL;
		s->size = 1;
		return ;
	}
	s->head->prev = e;
	e->prev = NULL;
	e->next = s->head;
	s->head = e;
	s->size++;
}

void	remove_back(t_stack *s)
{
	t_element	*temp;

	if (!s || !(s->tail))
		return ;
	if (s->size == 1)
	{
		free(s->tail);
		s->head = NULL;
		s->tail = NULL;
		s->size = 0;
		return ;
	}
	s->tail->prev->next = NULL;
	temp = s->tail;
	s->tail = s->tail->prev;
	s->size--;
	free(temp);
}

void	remove_front(t_stack *s)
{
	t_element	*temp;

	if (!s || !(s->size))
		return ;
	if (s->size == 1)
	{
		free(s->head);
		s->head = NULL;
		s->tail = NULL;
		s->size = 0;
		return ;
	}
	s->head->next->prev = NULL;
	temp = s->head;
	s->head = s->head->next;
	s->size--;
	free(temp);
}
