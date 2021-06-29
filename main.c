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
	for (int i = 0; i < 125; i++)
	{
		test = (char *)malloc(128);
		for (int i = 0; i < 128; i++)
			test[i] = 'a';
	}	
	for (int i = 0; i < 125; i++)
	{
		test = (char *)malloc(129);
		for (int i = 0; i < 512; i++)
			test[i] = 'a';
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
		//munmap(g_heap, g_heap->total_size);
		g_heap = g_heap->next;
	}
	printf("Sizeof t_block == %d\n", sizeof(t_block));
	return (0);
}
