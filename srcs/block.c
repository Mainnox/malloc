/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:54:19 by akremer           #+#    #+#             */
/*   Updated: 2021/07/02 14:03:02 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static t_block	*fillfreed(t_heap *heap)
{
	t_block *block_tmp;

	block_tmp = heap->block;
	while (block_tmp)
	{
		if (block_tmp->freed)
			return (block_tmp);
		block_tmp = block_tmp->next;
	}
	return (NULL);
}

t_block		*createnewblock(t_heap *act_page, size_t size, char type)
{
	t_block	*new_block = NULL;

	if (act_page->block_freed)
	{
		new_block = fillfreed(act_page);
		act_page->block_freed--;
		new_block->freed = false;
	}
	else
	{
		if (!act_page->block)
			new_block = (void *)act_page + sizeof(t_heap);
		else
		{
			if (type == TINY)
				new_block = (void *)act_page->block + TINY_BLOCK_SIZE + sizeof(t_block);
			else if (type == SMALL)
				new_block = (void *)act_page->block + SMALL_BLOCK_SIZE + sizeof(t_block);
		}
		act_page->block_count++;
		if (act_page->block)
			new_block->next = act_page->block;
		else
			new_block->next = NULL;
		new_block->freed = false;
		act_page->block = new_block;
	}
	new_block->data_size = size;
	return ((void *)new_block + sizeof(t_block));
}
