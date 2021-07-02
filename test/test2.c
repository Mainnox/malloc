#include "../includes/malloc.h"

int 		main()
{
	int		i;
	char	*addr;

	i = 0;
	while (i < 1024)
	{
		addr = (char *)malloc(1024);
		addr[0] = 42;
		free(addr);
		i++;
	}
	//show_alloc_mem();
	/*
	while (g_heap)
	{
		char *type = (char *)g_heap;
		if (*type == TINY)
			hexDump("Heap TINY", (void *)g_heap, TINY_HEAP_ALLOCATION_SIZE);
		if (*type == TINY)
			hexDump("Heap SMALL", (void *)g_heap, SMALL_HEAP_ALLOCATION_SIZE);
		if (*type == TINY)
			hexDump("Heap LARGE", (void *)g_heap, g_heap->total_size);
		g_heap = g_heap->next;
	}
	*/
	return (0);
}
