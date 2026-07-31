#include "push_swap.h"

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

#include <stdio.h>
int main(){
	int found = 0;
	int *arr = malloc(5 * sizeof(int));
	int used[100000];
	for (int i = 0; i < 100000; i++) used[i] = 0;

	while (found != 120)
	{
		random_permutation(arr, 5);
		int code = arr[0] * 10000 + arr[1] * 1000 + arr[2] * 100 + arr[3] * 10 + arr[4];
		if (!used[code]){
			used[code] = 1;
			for(int i = 0; i < 5; i++) printf("%d ", arr[i]);
			printf("\n");
			found++;
		}
	}
}
