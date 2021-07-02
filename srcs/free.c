/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:49:34 by akremer           #+#    #+#             */
/*   Updated: 2021/07/02 14:01:45 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_heap		*findheap(t_block **hime)
{
	t_heap	*heap_tmp = g_heap;
	t_block	*him = *hime;
	
	while (heap_tmp)
	{
		if (heap_tmp->type == TINY)
			if (((void *)him - (void *)heap_tmp) <= (long)TINY_HEAP_ALLOCATION_SIZE)
				return (heap_tmp);
		if (heap_tmp->type == SMALL)
			if (((void *)him - (void *)heap_tmp) <= (long)SMALL_HEAP_ALLOCATION_SIZE)
				return (heap_tmp);
		if (heap_tmp->type == LARGE)
			if (((void *)him - (void *)heap_tmp) <= (long)heap_tmp->total_size)
				return (heap_tmp);
		heap_tmp = heap_tmp->next;
	}
	return (NULL);
}

void		free(void *ptr)
{
	t_heap	*heap;
	t_heap	*heap_tmp;
	t_block	*block;

	if (!ptr || !(heap = findheap((t_block **)&ptr)))
		return ;
	block = (t_block *)(ptr - sizeof(t_block));
	block->freed = true;
	heap->block_freed++;
	if (heap->block_count == heap->block_freed)
	{
		if (heap == g_heap)
			g_heap = g_heap->next;
		else
		{
			heap_tmp = g_heap;
			while (heap_tmp->next != heap)
				heap_tmp = heap_tmp->next;
			heap_tmp->next = heap->next;
		}
		munmap(heap, heap->total_size);
	}
}
