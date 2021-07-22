#include "malloc.h"

extern t_heap *g_heap;

void		*realloc(void *ptr, size_t size)
{
	void		*ret;
	t_block		*s;

	ret = malloc(size);
	if (ret && ptr)
	{
		s = (t_block *)(ret - (sizeof(t_block)));
		if (s->data_size <= size)
			ft_memcpy(ptr, ret, s->data_size);
		else
			ft_memcpy(ptr, ret, size);
	}
	free(ptr);
	return (ret);
}
