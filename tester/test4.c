#include "malloc.h"
#include <unistd.h>
#include <string.h>

void	print(char *ptr)
{
	write(1, ptr, strlen(ptr));
}

int		main(void)
{
	char	*addr = (char *)malloc(16);

	free(NULL);
	free((void *)addr + 5);
	if (realloc((void *)addr + 5, 10) == NULL)
		print("bonjours\n");
	return (0);
}
