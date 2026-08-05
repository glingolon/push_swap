#include "../push_swap.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char **splat = ft_split(argv[1], ' ');
		int last_num = 0;
		for(int i = 0; splat[i]; i++){
			if (atoi(splat[i]) <= last_num)
			{
				printf("ERROR\n");
				return (0);
			}
			last_num = atoi(splat[i]);
		}
		printf("OK\n");
		return (0);
	}
	int last_num = 0;
	for(int i = 1; i < argc; i++)
	{
		if (atoi(argv[i]) <= last_num){
			printf("ERROR\n");
			return (0);
		}
		last_num = atoi(argv[i]);
	}
	printf("OK\n");
}
