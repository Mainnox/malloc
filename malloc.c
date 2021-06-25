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

t_block		*createnewblock(t_heap *where, size_t size)
{
	t_block	*new_block = (t_block *)where;

	if (size < TINY_BLOCK_SIZE)
	{
		new_block->next = NULL;
		new_block->data_size = TINY_BLOCK_SIZE;
		return (new_block);
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
		new_heap->type = 1;
		new_heap->total_size = TINY_HEAP_ALLOCATION_SIZE;
		new_heap->next = NULL;
		new_heap->block = NULL;
		new_heap->block_count = 0;
		return (new_heap);
	}
	return (NULL);
}

static char	taketype(size_t size)
{
	char ret;

	if (size < TINY_BLOCK_SIZE)
		ret = TINY;
	else if (size < SMALL_BLOCK_SIZE)
		ret = SMALL;
	else
		ret = LARGE;
	return (ret);
}

t_heap		*checkifheapmatch(char type)
{
	t_heap	*heap_tmp = g_heap;

	while (heap_tmp)
	{
		if (heap_tmp->type = type)
			return (heap_tmp);
		heap_tmp = heap_tmp->next;
	}
	return (NULL);
}

void		*malloc(size_t size)
{
	char	type = taketype(size);

	if (!g_heap)
		g_heap = createnewheap(size, type);
	else
	{
		t_heap *save = checkifheapmatch(type);
		if (save)
			;	// Grab the adress where do you want to put the block and place it 
		else
		{
			t_heap *first = createnewheap(size, type);
			first->next = g_heap;
			g_heap = first;

		}
	}
	//		Check if you have a pages ready with the good type and with space for the block
	//
	//		Grab the address where do you want to put the block
	//
	//		Put the blocks at the good area
	//
	//		Return the adress of the block
	return (NULL);
}
