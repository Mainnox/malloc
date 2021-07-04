#include "includes/malloc.h"

int			main()
{
	char *test1;
	char *test2;

	test1 = (char *)malloc(128);
	for (int i = 0; i < 128; i++)
		test1[i] = 'K';
	for (int i = 0; i < 1024; i++)
		test2 = realloc(test2, 229);
	free(test2);
	show_alloc_mem_hexdump();
	return (0);
}
