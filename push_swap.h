/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 22:39:48 by mwisniew          #+#    #+#             */
/*   Updated: 2026/07/25 20:17:51 by nfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_element
{
	int	val;
	struct s_element	*next;
	struct s_element	*prev;
}						t_element;

typedef struct s_stack
{
	t_element	*head;
	t_element	*tail;
	int	size;
}				t_stack;

void	compress(int *arr, int n);
void	add_back(t_stack *s, t_element *e);
void	remove_back(t_stack *s);
void	add_front(t_stack *s, t_element *e);
void	remove_front(t_stack *s);
void	swap_stack(t_stack *st);
void	swap_stacks(t_stack *a, t_stack *b);
void	push_stack_a(t_stack *a, t_stack *b);
void	push_stack_b(t_stack *a, t_stack *b);
void	rotate_stack(t_stack *st);
void	rotate_stacks(t_stack *a, t_stack *b);
void	rev_rotate_stack(t_stack *st);
void	rev_rotate_stacks(t_stack *a, t_stack *b);
#endif
