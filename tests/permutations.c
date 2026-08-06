#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);
	int seed;

	if (argc == 2)	seed = time(NULL);
	else	seed = atoi(argv[2]);

	srand(seed);
	if (argc == 1) return 0;
	int *arr = malloc ((n + 1)  * sizeof(int));
	random_permutation(arr, n);
	for(int i = 0; i < n; i++) printf("%d ", arr[i]);
}
