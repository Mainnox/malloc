/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:26:16 by akremer           #+#    #+#             */
/*   Updated: 2021/06/29 11:07:13 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		main()
{
	char		*test2;
	char		*test3;
	char		*test4;
	char		*test5;
	char		*test6;
	char		*test7;
	char 		*test;

	printf("getpagesize = %d\n", getpagesize());
	printf("[size tiny]\n1 = %d\n2 = %d\n\n[size small]\n1 = %d\n2 = %d\n", TINY_HEAP_ALLOCATION_SIZE, TINY_BLOCK_SIZE, SMALL_HEAP_ALLOCATION_SIZE, SMALL_BLOCK_SIZE);
//	for (int i = 0; i < 125; i++)
//	{
//		test = (char *)malloc(128);
//		for (int i = 0; i < 128; i++)
//			test[i] = 'a';
//	}	
//	for (int i = 0; i < 125; i++)
//	{
//		test = (char *)malloc(128);
//		for (int i = 0; i < 128; i++)
//			test[i] = 'a';
//		free(test);
//	}	
//	test = (char *)malloc(520);
//	for (int i = 0; i < 520; i++)
//		test[i] = 'c';
//	free(test);
	for (int i = 0; i < 100; i++)
	{
		printf("Appel numero %d\n", i);
		test = (char *)malloc(128);
		for (int i = 0; i < 128; i++)
			test[i] = 'c';
		if (i == 10 || i == 50 || i == 99)
			free(test);
	}
	for (int i = 0; i < 3; i++)
	{
		test = (char *)malloc(128);
			for (int i = 0; i < 128; i++)
				test[i] = 'd';
	}
	while (g_heap)
	{
		char *type = (char *)g_heap;
		if (*type == TINY)
			hexDump("Heap TINY", g_heap, TINY_HEAP_ALLOCATION_SIZE);
		if (*type == SMALL)
			hexDump("Heap SMALL", g_heap, SMALL_HEAP_ALLOCATION_SIZE);
		if (*type == LARGE)
			hexDump("Heap LARGE", g_heap, g_heap->total_size);
		printf("block_count = %d\n", g_heap->block_count);
		printf("block_freed == %d\n", g_heap->block_freed);
		printf("interval = %ld\n", (void *)g_heap->block - (void *)g_heap);
		g_heap = g_heap->next;
	}
	printf("heap p = %p\nblock p = %p\n", &g_heap, &g_heap->block);
	printf("Sizeof t_block == %d\n", sizeof(t_block));
	return (0);
}
