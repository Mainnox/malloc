#include "malloc.h"

int		main(void)
{
	void *ptr = NULL;

  (void)ptr;
	ptr = malloc(1024);
	ptr = malloc(1024 * 32);
	ptr = malloc(1024 * 1024);
	ptr = malloc(1024 * 1024 * 16);
	ptr = malloc(1024 * 1024 * 128);
	return (0);
}
