#include "malloc.h"
#include <unistd.h>
#include <string.h>

#define M (1024*1024)

void	print(char *ptr)
{
	write(1, ptr, strlen(ptr));
}

int		main(void)
{
	char *addr1;
	char *addr3;

	addr1 = (char *)malloc(16 * M);
	strcpy(addr1, "bonjours\n");
	print(addr1);
	addr3 = realloc(addr1, 128 * M);
	addr3[127 * M] = 42;
	print(addr3);
	return (0);
}
