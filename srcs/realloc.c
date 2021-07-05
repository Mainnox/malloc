#include "malloc.h"

extern t_heap *g_heap;

void		*realloc(void *ptr, size_t size)
{
	void		*ret;
	t_block		*s;

	ret = malloc(size);
	printf("Realloc start\n");
	printf("realloc ptr = %p\n", ptr);
	printf("realloc ret = %p\n", ret);
	if (ret && ptr)
	{
		s = (t_block *)(ret - (sizeof(t_block)));
		printf("s->sata_size = %zu\n", s->data_size);
		if (s->data_size < size)
			memcpy(ret, ptr, s->data_size);
		else
			memcpy(ret, ptr, size);
	}
	free(ptr);
	return (ret);
}
