/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:26:16 by akremer           #+#    #+#             */
/*   Updated: 2021/07/02 16:15:42 by akremer          ###   ########.fr       */
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
		test = (char *)malloc(128);
		for (int i = 0; i < 128; i++)
			test[i] = 'a';
		free(test);
	}	
	test = (char *)malloc(520);
	for (int i = 0; i < 520; i++)
		test[i] = 'c';
	free(test);
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
		test = (char *)malloc(512);
			for (int i = 0; i < 512; i++)
				test[i] = 'd';
	}
	test = (char *)malloc(1001);
	for (int i = 0; i < 1001; i++)
		test[i] = 'K';
	t_heap	*heap = g_heap;
	while (heap)
	{
		char *type = (char *)heap;
		if (*type == TINY)
			hexDump("Heap TINY", heap, TINY_HEAP_ALLOCATION_SIZE);
		if (*type == SMALL)
			hexDump("Heap SMALL", heap, SMALL_HEAP_ALLOCATION_SIZE);
		if (*type == LARGE)
			hexDump("Heap LARGE", heap, heap->total_size);
		printf("block_count = %d\n", heap->block_count);
		heap = heap->next;
	}
	return (0);
}
