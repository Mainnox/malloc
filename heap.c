/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:51:20 by akremer           #+#    #+#             */
/*   Updated: 2021/06/29 11:39:30 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static bool	freeplacepage(t_heap *heap, char type)
{
	if (type == TINY)
		if (heap->block_count < MAX_TINY_BLOCK || heap->block_freed)
			return (true);
	if (type == SMALL)
		if (heap->block_count < MAX_SMALL_BLOCK || heap->block_freed)
			return (true);
	return (false);
}

t_heap		*checkifheapmatch(char type)
{
	t_heap	*heap_tmp = g_heap;

	if (type == LARGE)
		return (NULL);
	while (heap_tmp)
	{
		if (heap_tmp->type == type)
			if (freeplacepage(heap_tmp, type))
				return (heap_tmp);
		heap_tmp = heap_tmp->next;
	}
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
		new_heap->block_freed = 0;
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
		new_heap->block_freed = 0;
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
		new_heap->block_freed = 0;
		new_heap->block = NULL;
		return (new_heap);
	}
	return (NULL);
}
