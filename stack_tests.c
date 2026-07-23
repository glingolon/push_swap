/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwisniew <mwisniew@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:16:47 by mwisniew          #+#    #+#             */
/*   Updated: 2026/07/23 18:38:12 by nfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SWAP ;
//#define ROTATE ;
//#define REV_ROTATE ; 
int main()
{
	t_stack a, b;
	a.head = NULL;
	b.head = NULL;
	a.tail = NULL;
	b.tail = NULL;
	a.size = 0;
	b.size = 0;
	
	while (1)
	{
		printf("\nstack A: ");
		for (t_element *cur = a.head; cur; cur = cur->next)
			printf("%d ", cur->val);
		printf("\nstack B: ");
		for (t_element *cur = b.head; cur; cur = cur->next)
			printf("%d ", cur->val);
		printf("\n\n");
		
		printf("Options: \n\tAdd front: addf <stack> <value>\n");
		printf("\tAdd back: addb <stack> <value>\n");
		printf("\tRemove front: remf <stack>\n");
		printf("\tRemove back: remb <stack>\n");
		char command[100];
		scanf("%s", command);

		if (!strncmp(command, "add", 3))
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
#ifdef SWAP
		else if (!strncmp(command, "swap", 4))
		{
			char stack_name;
			scanf("%c", &stack_name);
			t_stack *stack = (stack_name == 'a') ? &a : &b;
			swap_stack(stack);
		}
#endif
#ifdef ROTATE
		else if (!strncmp(command, "rot", 3))
		{
			char stack_name;
			scanf("%c", &stack_name);
			t_stack *stack = (stack_name == 'a') ? &a : &b;
			rotate_stack(stack);
		}
#endif
#ifdef REV_ROTATE
		else if (!strncmp(command, "revrot", 3))
		{
			char stack_name;
			scanf("%c", &stack_name);
			t_stack *stack = (stack_name == 'a') ? &a : &b;
			rev_rotate_stack(stack);
		}
#endif
		//printf("\x1B[2J\n"); 
		system("clear");
	}
}
