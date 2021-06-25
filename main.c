/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:26:16 by akremer           #+#    #+#             */
/*   Updated: 2021/06/25 19:46:39 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		main()
{
	char		*test;
	char		*test2;
	char		*test3;
	char		*test4;
	char		*test5;
	char		*test6;
	char		*test7;
	char		*test8;

	printf("getpagesize = %d\n", getpagesize());
	printf("[size tiny]\n1 = %d\n2 = %d\n\n[size small]\n1 = %d\n2 = %d\n", TINY_HEAP_ALLOCATION_SIZE, TINY_BLOCK_SIZE, SMALL_HEAP_ALLOCATION_SIZE, SMALL_BLOCK_SIZE);
	test = (char *)malloc(129);
	test2 = (char *)malloc(128);
	test3 = (char *)malloc(128);
	test4 = (char *)malloc(128);
	test5 = (char *)malloc(128);
	test6 = (char *)malloc(128);
	test7 = (char *)malloc(128);
	test8 = (char *)malloc(28000);
	for (int i = 0; i < 129; i++)
		test[i] = 'c';
	for (int i = 0; i < 128; i++)
		test2[i] = 'd';
	for (int i = 0; i < 128; i++)
		test3[i] = 'q';
	for (int i = 0; i < 128; i++)
		test4[i] = 'a';
	for (int i = 0; i < 128; i++)
		test5[i] = 'z';
	for (int i = 0; i < 128; i++)
		test6[i] = 'x';
	for (int i = 0; i < 128; i++)
		test7[i] = 'v';
	for (int i = 0; i < 28000; i++)
		test8[i] = 'k';
	while (g_heap)
	{
		char *type = (char *)g_heap;
		if (*type == TINY)
			hexDump("Heap TINY", g_heap, TINY_HEAP_ALLOCATION_SIZE);
		if (*type == SMALL)
			hexDump("Heap SMALL", g_heap, SMALL_HEAP_ALLOCATION_SIZE);
		if (*type == LARGE)
			hexDump("Heap LARGE", g_heap, g_heap->total_size);
		g_heap = g_heap->next;
	}
	return (0);
}
