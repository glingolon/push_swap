#include "push_swap.h"
#include <stdio.h>
int	main(int argc, char *argv[])
{
	int			i;
	int			n;
	int			*arr;
	t_element	*new_element;
	t_stack		a;
	t_stack		b;
	init_stack(&a);
	init_stack(&b);
	//fill_input(&input, argc, argv);

//	printf("mode: %d\nbench: %d\n", input.algorithm_complexity, input.bench);
	//fill_stack(a);
	//fill_stack(b);
	n = argc - 1;
	i = 0;
	if (n == 1)
	{
		char	**splat;
		splat = ft_split(argv[1], ' ');
		n = 0;
		for(int i = 0; splat[i]; i++) n++;
		arr = malloc ((n + 1) * sizeof(int));
		for(int i = 0; i < n; i++)
			arr[n - i - 1] = atoi(splat[i]);
	}
	else
	{
		arr = malloc ((n + 1) * sizeof(int));
		while (i < n)
		{
			arr[n - i - 1] = ft_atoi(argv[i + 1]);
			i++;
		}
	}
	compress(arr, n);
	i = 0;
	while (i < n)
	{
		new_element = malloc(sizeof(t_element));
		new_element->val = arr[i];
		add_back(&a, new_element);
		i++;
	}
	if (n < 6)
		small_input(&a, &b);
	else
//	simple_sort(&a, &b);
		medium_sort(&a, &b);
//	for(t_element *c = a.tail; c; c = c->prev) printf("%d\n", c->val);
}
