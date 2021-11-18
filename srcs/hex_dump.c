/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_dump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:48:25 by akremer           #+#    #+#             */
/*   Updated: 2021/11/18 14:45:11 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "malloc.h"

void hexDump(char *desc, void *addr, int len) 
{
    int i;
    unsigned char buff[17];
    unsigned char *pc = (unsigned char*)addr;

    if (desc != NULL)
        printf ("%s:\n", desc);

    for (i = 0; i < len; i++) {
        if ((i % 16) == 0) {
            if (i != 0)
                printf("  %s\n", buff);
            printf("  %04x ", i);
       	}
	i % 16 == 7 ? printf(" %02x -", pc[i]) : printf(" %02x", pc[i]);
        if ((pc[i] < 0x20) || (pc[i] > 0x7e)) {
            buff[i % 16] = '.';
        } else {
            buff[i % 16] = pc[i];
        }
        buff[(i % 16) + 1] = '\0';
    }
    while ((i % 16) != 0) {
        printf("   ");
        i++;
    }
    printf("  %s\n", buff);
}
void	show_alloc_mem_hexdump()
{
	t_heap	*heap = g_heap;
	int	i = 0;

	while (heap)
	{
		char *type = (char *)heap;
		if (*type == TINY)
			hexDump("Heap TINY", heap, TINY_HEAP_ALLOCATION_SIZE);
		if (*type == SMALL)
			hexDump("Heap SMALL", heap, SMALL_HEAP_ALLOCATION_SIZE);
		if (*type == LARGE)
			hexDump("Heap LARGE", heap, heap->total_size);
		printf("block_count = %d\n", heap->block_count);
		heap = heap->next;
		i++;
	}
	printf("number of pages = %d\n", i);
}
