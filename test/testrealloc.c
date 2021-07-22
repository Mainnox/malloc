#include "../includes/malloc.h"

int			main()
{
	char *test = malloc(1000);
	for (int i = 0; i < 1000; i++)
		test[i] = 'Q';
	test = realloc(test, 1000);
	test[0] = 'f';

	for (int i = 0; i < 1024; i++)
	{
		test = realloc(NULL, 1024);
		printf("C'est ici !\n");
		for (int i = 0; i < 1024; i++)
			test[i] = 'G';
	}
	return (0);
}
