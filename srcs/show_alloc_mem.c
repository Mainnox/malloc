/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 10:22:20 by akremer           #+#    #+#             */
/*   Updated: 2021/07/02 11:56:02 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		show_blocks(t_block *block, char type, size_t *total_size, char *i)
{
	if (block->next)
		show_blocks(block->next, type, total_size, i);
	ft_putstr("#");
	ft_putnbr_base(*i, 10, "0123456789");
	*i += 1;
	ft_putstr(" 0x");
	ft_putnbr_base((long)block, 16, "0123456789ABCDEF");
	ft_putstr(" - 0x");
	*total_size += block->data_size;
	ft_putnbr_base((long)block + block->data_size, 16, "0123456789ABCDEF");
	ft_putstr(" ");
	ft_putnbr_base(*total_size, 10, "0123456789");
	ft_putstr(" octets\n");
}

static void		show_alloc_mem_recu(t_heap	*heap, size_t *total_size)
{

	if (heap->next)
		show_alloc_mem_recu(heap->next, total_size);
	if (heap->type == TINY)
		ft_putstr("TINY : 0x");
	if (heap->type == SMALL)
		ft_putstr("SMALL : 0x");
	if (heap->type == LARGE)
		ft_putstr("LARGE : 0x");
	ft_putnbr_base((long)heap, 16, "0123456789ABCDEF");
	ft_putstr("\n\n");
	char i = 0;
	show_blocks(heap->block, heap->type, total_size, &i);
	ft_putstr("\n");
}

void			show_alloc_mem()
{
	size_t		total_size = 0;
	t_heap *heap = g_heap;
	show_alloc_mem_recu(heap, &total_size);
}
