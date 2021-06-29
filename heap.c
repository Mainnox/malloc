/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:51:20 by akremer           #+#    #+#             */
/*   Updated: 2021/06/25 19:46:33 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_heap		*checkifheapmatch(char type)
{
	t_heap	*heap_tmp = g_heap;

	if (type == LARGE)
		return (NULL);
	while (heap_tmp)
	{
		if (heap_tmp->type == type)
			return (heap_tmp);
		heap_tmp = heap_tmp->next;
	}
	printf("check if heap match = NULL\n");
	return (NULL);
}

t_heap		*createnewheap(size_t size, char type)
{
	t_heap	*new_heap;

	if (type == TINY)
	{
		new_heap = (t_heap *)mmap(NULL, TINY_HEAP_ALLOCATION_SIZE
				, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
		new_heap->type = TINY;
		new_heap->total_size = TINY_HEAP_ALLOCATION_SIZE;
		new_heap->next = NULL;
		new_heap->block_count = 0;
		new_heap->block = NULL;
		return (new_heap);
	}
	if (type == SMALL)
	{
		new_heap = (t_heap *)mmap(NULL, SMALL_HEAP_ALLOCATION_SIZE
				, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
		new_heap->type = SMALL;
		new_heap->total_size = SMALL_HEAP_ALLOCATION_SIZE;
		new_heap->next = NULL;
		new_heap->block_count = 0;
		new_heap->block = NULL;
		return (new_heap);
	}
	if (type == LARGE)
	{
		new_heap = (t_heap *)mmap(NULL, size
				, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
		new_heap->type = LARGE;
		new_heap->total_size = size;
		new_heap->next = NULL;
		new_heap->block_count = 0;
		new_heap->block = NULL;
		return (new_heap);
	}
	return (NULL);
}
