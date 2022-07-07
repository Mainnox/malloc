/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 10:45:12 by akremer           #+#    #+#             */
/*   Updated: 2021/11/18 17:45:27 by akremer          ###   ########.fr       */
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
#define TINY_HEAP_ALLOCATION_SIZE (8UL * getpagesize())
#define TINY_BLOCK_SIZE (TINY_HEAP_ALLOCATION_SIZE / 128) 
#define MAX_TINY_BLOCK 107
#define MAX_SMALL_BLOCK 122
#define SMALL_HEAP_ALLOCATION_SIZE (32UL * getpagesize())
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

typedef struct			s_block
{
	bool			freed;
	size_t			data_size;
	struct s_block		*next;
}				t_block;

typedef struct 		s_heap
{
	char			type;
	unsigned char	block_freed;
	char			block_count;
	size_t			total_size;
	t_block			*block;
	struct s_heap	*next;
}			t_heap;

extern t_heap *g_heap;

/*
 *	Tool's functions
 */

void		hexDump(char *desc, void *addr, int len);
void		*ft_memcpy(void *dest, const void *src, size_t size);
void		ft_putstr(char *str);
void		show_alloc_mem(void);
void		ft_putnbr_base(long nb, int b, char *base);
void		show_alloc_mem_hexdump(void);
char		*ft_strncpy(char *dest, const char *src, size_t len);
void		print(char *ptr);
int			ft_strlen(char *str);
void		print_macro_allo(void);

/*
 *	Heap's functions
 */

t_heap		*checkifheapmatch(char type);
t_heap		*createnewheap(size_t size, char type);
t_heap		*findheap(t_block **hime);

/*
 *	Block's functions
 */

t_block		*createnewblock(t_heap *act_page, size_t size, char type);
t_block		*wheretoplaceblock(t_heap *act_page);
t_block		*findblock(t_heap *heap, void *ptr);

/*
 *	Main's functions
 */

void		*malloc(size_t size);
void		free(void *ptr);
void		*realloc(void *ptr, size_t size);
void		*calloc(size_t nmbr, size_t size);

#endif
