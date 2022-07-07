/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:49:34 by akremer           #+#    #+#             */
/*   Updated: 2021/11/18 16:59:55 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static int	checkotherheap(char type)
{
	t_heap	*heap_tmp;
	int		count;

	if (type == LARGE)
		return (0);
	heap_tmp = g_heap;
	count = 0;
	while (heap_tmp)
	{
		if (heap_tmp->type == type)
			count++;
		heap_tmp = heap_tmp->next;
	}
	return (count);
}

t_heap		*findheap(t_block **hime)
{
	t_heap	*heap_tmp = g_heap;
	t_block	*him = *hime;
	
	while (heap_tmp)
	{
		if (heap_tmp->type == TINY)
			if (((void *)heap_tmp < (void *)him) && (void *)heap_tmp
					+ (long)TINY_HEAP_ALLOCATION_SIZE >= (void *)him)
				return (heap_tmp);
		if (heap_tmp->type == SMALL)
			if (((void *)heap_tmp < (void *)him) && (void *)heap_tmp
					+ (long)SMALL_HEAP_ALLOCATION_SIZE >= (void *)him)
				return (heap_tmp);
		if (heap_tmp->type == LARGE)
			if (((void *)heap_tmp < (void *)him) && (void *)heap_tmp
					+ (size_t)heap_tmp->total_size >= (void *)him)
				return (heap_tmp);
		heap_tmp = heap_tmp->next;
	}
	return (NULL);
}

t_block		*findblock(t_heap *heap, void *ptr)
{
	t_block	*block_tmp;

	block_tmp = heap->block;
	while (block_tmp)
	{
		if ((void *)block_tmp == ptr - (long)sizeof(t_block))
			return (block_tmp);
		block_tmp = block_tmp->next;
	}
	return (NULL);
}

void		free(void *ptr)
{
	t_heap	*heap;
	t_heap	*heap_tmp;
	t_block	*block;

	heap = NULL;
	block = NULL;
	heap_tmp = NULL;
	if (!ptr || !(heap = findheap((t_block **)&ptr)))
		return ;
	block = findblock(heap, ptr);
	if (!block)
		return ;
	block->freed = true;
	heap->block_freed++;
	if (heap->block_count == heap->block_freed && !checkotherheap(heap->type))
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
		if (!checkotherheap(heap->type))
			munmap(heap, heap->total_size);
	}
}
