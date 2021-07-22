#include "malloc.h"

static void	fillcalloc(char *ptr, size_t size)
{
	for (size_t i = 0; i < size; i++)
		ptr[i] = 0;
}

void		*calloc(size_t nmbr, size_t size)
{
	void *ret;

	printf("Calloc start\n");
	ret = malloc(nmbr * size);
	if (!ret)
		return (NULL);
	fillcalloc(ret, nmbr * size);
	printf("Calloc done\n");
	return (ret);
}
