/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:54:19 by akremer           #+#    #+#             */
/*   Updated: 2021/06/25 19:46:35 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_block		*createnewblock(t_heap *act_page, size_t size, char type)
{
	t_block	*new_block;					// = act_page->block + sizeof(t_block)
										//	+ act_page->block->data_size;
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
	new_block->data_size = size;
	act_page->block = new_block;
	return ((void *)new_block + sizeof(t_block));
}
