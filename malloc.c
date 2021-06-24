/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 10:45:05 by akremer           #+#    #+#             */
/*   Updated: 2021/06/24 16:58:13 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block		*createnewblock(size_t size)
{
	t_block	*new_block;

	if (size < TINY_BLOCK_SIZE)
	{
		new_block->next = NULL;
		new_block->data_size = TINY_BLOCK_SIZE;
		return (new_block);
	}
	return (NULL);
}

t_heap		*createnewheap(size_t size)
{
	t_heap	*new_heap;

	{
		new_heap = (t_heap *)mmap(NULL, TINY_HEAP_ALLOCATION_SIZE
				, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
		new_heap->type = 1;
		new_heap->total_size = TINY_HEAP_ALLOCATION_SIZE;
		new_heap->next = NULL;
		new_heap->block = NULL;
		new_heap->block_count = 0;
		return (new_heap);
	}
	return (NULL);
}

void		*malloc(size_t size)
{
	//				Check we have a pages for this size
	if (!g_heap)
		g_heap = createnewheap(size);
	//				Made the block for the designed page
	return (NULL);
}
