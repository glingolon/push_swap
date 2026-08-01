#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    t_input input;
    int i;

    fill_input(&input, argc, argv);

    printf("Bench: %d\n", input.bench);
    printf("Complexity: %d\n", input.algorithm_complexity);
    printf("Array Length: %d\n", input.arr_len);
    
    printf("Numbers: ");
    for (i = 0; i < input.arr_len; i++)
        printf("%d ", input.init_arr[i]);
    printf("\n");

    // (Free input.init_arr here)
    return (0);
}
