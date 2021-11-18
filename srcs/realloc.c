#include "malloc.h"

extern t_heap *g_heap;

void		*realloc(void *ptr, size_t size)
{
	void		*ret;
	void		*tmp_ptr;
	t_block		*s;

	tmp_ptr = ptr;
	ret = malloc(size);
	if (ret && ptr)
	{
		s = (t_block *)(tmp_ptr - (sizeof(t_block)));
		printf("s->data_size = %zu\n", s->data_size);
		printf("size = %zu\n", size);
		if (s->data_size <= size)
			ft_strncpy(tmp_ptr, ret, s->data_size);
		else
			ft_strncpy(tmp_ptr, ret, size);
	}
//	hexDump("test", ret - sizeof(t_block) - sizeof(t_heap), 1064);
	free(ptr);
	return (ret);
}
