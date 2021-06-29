/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 10:45:12 by akremer           #+#    #+#             */
/*   Updated: 2021/06/29 11:07:11 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
#define MALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
 *	Define size of heap and navigation macro
 */

#define HEAP_SHIFT(start) ((void *)start + sizeof(t_heap))
#define BLOCK_SHIFT(start) ((void *)start + sizeof(t_block))
#define TINY_HEAP_ALLOCATION_SIZE (4 * getpagesize())
#define TINY_BLOCK_SIZE (TINY_HEAP_ALLOCATION_SIZE / 128)
#define MAX_TINY_BLOCK 107
#define MAX_SMALL_BLOCK 122
#define SMALL_HEAP_ALLOCATION_SIZE (16 * getpagesize())
#define SMALL_BLOCK_SIZE (SMALL_HEAP_ALLOCATION_SIZE / 128)
#define bool char
#define true 1
#define false 0
#define TEST -255
#define TINY 1
#define SMALL 2
#define LARGE 3

/*
 *	Heap struct with metadata
 *	Same for blocks
 */

typedef struct		s_block
{
	bool			freed;
	struct s_block	*next;
	size_t			data_size;
}			t_block;

typedef struct 		s_heap
{
	char			type;
	unsigned char			block_freed;
	char			block_count;
	size_t			total_size;
	t_block			*block;
	struct s_heap	*next;
}			t_heap;

t_heap *g_heap;

/*
 *	Tool's functions
 */

void		hexDump(char *desc, void *addr, int len);

/*
 *	Heap's functions
 */

t_heap		*checkifheapmatch(char type);
t_heap		*createnewheap(size_t size, char type);

/*
 *	Block's functions
 */

t_block		*createnewblock(t_heap *act_page, size_t size, char type);
t_block		*wheretoplaceblock(t_heap *act_page);

/*
 *	Main's functions
 */

void		*malloc(size_t size);
void		free(void *ptr);

#endif
