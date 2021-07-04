#include "malloc.h"

void		*realloc(void *ptr, size_t size)
{
	void		*ret;
	t_block		*s;

	ret = malloc(size);
	if (ret && ptr)
	{
		s = (t_block *)(ret - (sizeof(t_block)));
		if (s->data_size < size)
			ft_memcpy(ret, ptr, s->data_size);
		else
			ft_memcpy(ret, ptr, size);
	}
	free(ptr);
	printf("caca\n");
	return (ret);
}
