#include "malloc.h"

int		main()
{
	char	*test;
	void	*joujou;
	t_block *tmp;

	test = (char *)malloc(10);
	for (int i = 0; i < 10; i++)
		test[i] = 'K';
	joujou = (void *)test;
	joujou -= sizeof(t_block);
	test = (char *)malloc(10);
	for (int i = 0; i < 10; i++)
		test[i] = 'K';
	hexDump("", g_heap, 1280);
	free(test);
	hexDump("", g_heap->next, 1280);
	test = (char *)malloc(10);
	hexDump("", g_heap->next, 1280);
	printf("T_heap size = %d\n", sizeof(t_heap));
	return (0);
}
