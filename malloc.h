#ifndef MALLOC_h
#define MALLOC_H

#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/*
 *	Define size of heap and navigation macro
 */

#define HEAP_SHIFT(start) ((void *)start + sizeof(t_heap))
#define BLOCK_SHIFT(start) ((void *)start + sizeof(t_block))
#define TINY_HEAP_ALLOCATION_SIZE (4 * getpagesize())
#define TINY_BLOCK_SIZE (TINY_HEAP_ALLOCATION_SIZE / 128)
#define SMALL_HEAP_ALLOCATION_SIZE (16 * getpagesize())
#define SMALL_BLOCK_SIZE (SMALL_HEAP_ALLOCATION_SIZE / 128)
#define bool short
#define true 1
#define false 0

/*
 *	Heap struct with metadata
 *	Same for blocks
 */

typedef struct 		s_heap
{
	struct s_heap	*prev;
	struct s_heap	*next;
	//t_heap_group	group;
	size_t		total_size;
	size_t		block_count;
}			t_heap;

typedef struct		s_block
{
	struct s_block	*prev;
	struct s_block	*next;
	size_t		data_size;
	bool		freed;
}			t_block;

/*
 *	Main function
 */


#endif
