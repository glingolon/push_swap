/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:16:47 by mwisniew          #+#    #+#             */
/*   Updated: 2026/07/30 19:40:08 by mwisniew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void random_permutation(int *arr, int n)
{
	int appeared[n + 1];
	int found = 0;
	for (int i = 0; i <= n; i++) appeared[i] = 0;

	while (found != n)
	{
		int x = (rand() % n) + 1;
		if (!appeared[x])
		{
			appeared[x] = 1;
			arr[found] = x;
			found++;
		}
	}
}
#include <math.h>
void	print_stacks(t_stack *a, t_stack *b)
{
	int h = (a->size > b->size) ? a->size : b->size;
	t_element *cur_a = a->tail;
	t_element *cur_b = b->tail;

	for(int i = h; i; i--)
	{
		if (i <= a->size)
		{
			printf("  %d", cur_a->val);
			printf("\t");
			cur_a = cur_a->prev;
		}
		else printf(" \t");

		if (i <= b->size)
		{
			printf("  %d", cur_b->val);
			cur_b = cur_b->prev;
		}
		printf("\n");
	}
		printf("------------\n");
		printf("  A       B");
}
/*
int main()
{
	t_stack a, b;
	int	init[5] = {4, 2, 0, 6, 9};
	int	i;
	srand(time(NULL));


	a.head = NULL;
	b.head = NULL;
	a.tail = NULL;
	b.tail = NULL;
	a.size = 0;
	b.size = 0;

	for (i = 0; i < 5; i++)
	{
		t_element *new = malloc(sizeof(t_element));
		if (!new)
			break ;
		new->val = init[i];
		add_back(&a, new);
	}
	while (1)
	{
		print_stacks(&a, &b);
//		printf("\nstack A: ");
		//for (t_element *cur = a.head; cur; cur = cur->next)
		//	printf("%d ", cur->val);
	//	printf("\nstack B: ");
	//	for (t_element *cur = b.head; cur; cur = cur->next)
	//		printf("%d ", cur->val);
		printf("\n\n");
		
		printf("Options: \n\tAdd front: addf <stack> <value>\n");
		printf("\tAdd back: addb <stack> <value>\n");
		printf("\tRemove front: remf <stack>\n");
		printf("\tRemove back: remb <stack>\n");
		printf("\tSwap stack: swap <stack>\n");
		printf("\tSwap both: swapboth\n");
		printf("\tPush stack: push <stack>\n");
		printf("\tRotate stack: rot <stack>\n");
		printf("\tRotate both: rotboth\n");
		printf("\tReverse rotate stack: revrot <stack>\n");
		printf("\tReverse rotate both: revrotboth\n");
		printf("\tFill with random: rand <stack> <size>\n");
		char command[100];
		scanf("%s", command);
		
		if (!strncmp(command, "rand", 4))
		{
			char stack_name; int n;
			scanf(" %c %d", &stack_name, &n);
			t_stack *stack = (stack_name == 'a') ? &a : &b;
			
			while (stack->size) remove_front(stack);

			int *arr = malloc (sizeof(int) * (n + 1));
			random_permutation(arr, n);

			for(int i = 0; i < n; i++)
			{
				t_element *new_element = malloc(sizeof(t_element));
				new_element->val = arr[i];
				add_front(stack, new_element);
			}
		}

		else if (!strncmp(command, "add", 3))
		{
			char stack_name;
			int val;
			scanf(" %c %d", &stack_name, &val);
			t_stack *stack = (stack_name == 'a') ? &a : &b;
			t_element *new_element = malloc (sizeof(t_element));
			new_element->val = val;
			if (command[3] == 'f') add_front(stack, new_element);
			else add_back(stack, new_element);
		}
		else if (!strncmp(command, "rem", 3))
		{
			char stack_name;
			scanf(" %c", &stack_name);
			t_stack *stack = (stack_name == 'a') ? &a : &b;
			if (command[3] == 'f') remove_front(stack);
			else remove_back(stack);
		}
		else if(!strncmp(command, "swapboth", 8))
			swap_stacks(&a, &b);
		else if (!strncmp(command, "swap", 4))
		{
			char stack_name;
			scanf(" %c", &stack_name);
			t_stack *stack = (stack_name == 'a') ? &a : &b;
			swap_stack(stack);
		}
		else if(!strncmp(command, "push", 4))
		{
			char stack_name;
			scanf(" %c", &stack_name);
			if (stack_name == 'a')
				push_stack_a(&a, &b);
			else
				push_stack_b(&a, &b);
		}
		else if (!strncmp(command, "rotboth", 7))
			rotate_stacks(&a, &b);
		else if (!strncmp(command, "rot", 3))
		{
			char stack_name;
			scanf(" %c", &stack_name);
			t_stack *stack = (stack_name == 'a') ? &a : &b;
			rotate_stack(stack);
		}
		else if (!strncmp(command, "revrotboth", 10))
			rev_rotate_stacks(&a, &b);
		else if (!strncmp(command, "revrot", 6))
		{
			char stack_name;
			scanf(" %c", &stack_name);
			t_stack *stack = (stack_name == 'a') ? &a : &b;
			rev_rotate_stack(stack);
		}
		//printf("\x1B[2J\n"); 
		system("clear");
	}
}
*/
