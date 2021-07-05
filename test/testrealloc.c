#include "../includes/malloc.h"

int			main()
{
	char *test = malloc(1000);
	for (int i = 0; i < 1000; i++)
		test[i] = 'Q';
	printf("@ heap %p\n", g_heap);
	printf("@ test %p\n", test);
	test = realloc(test, 1000);
	printf("@ heap %p\n", g_heap);
	printf("@ test %p\n", test);
	test[0] = 'f';

	/*
	for (int i = 0; i < 1024; i++)
	{
		printf("test = %p\n", test);
		test = realloc(NULL, 1024);
		printf("C'est ici !\n");
		show_alloc_mem_hexdump();
		for (int i = 0; i < 1024; i++)
			test[i] = 'G';
	}
	*/
	return (0);
}
