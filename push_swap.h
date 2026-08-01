/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 22:39:48 by mwisniew          #+#    #+#             */
/*   Updated: 2026/07/31 19:35:50 by mwisniew         ###   ########.fr       */
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

typedef struct s_input
{
	int	bench;
	int	adaptive;
	int	algorithm_complexity;
	int	*init_arr;
	int	arr_len;
}				t_input;

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
void	simple_sort(t_stack *a, t_stack *b);
void	medium_sort(t_stack *a, t_stack *b);
void	init_stack(t_stack *s);
int	flags_input(t_input *input, int argc, char *argv[]);
void	fill_input(t_input *input, int argc, char *argv[]);
void	fill_input_split(t_input *input, char *str);
void	fill_from_args(t_input *input, int argc, char *argv[], int start);
void	small_input(t_stack *a, t_stack *b);
#endif
