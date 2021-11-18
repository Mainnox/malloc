#include "malloc.h"

int		main(void)
{
	int		i = 0;
	char	*addr = NULL;

	while (i < 1024)
	{
		addr = (char *)malloc(1024);
		addr[0] = 42;
		++i;
	}
	return (0);
}
