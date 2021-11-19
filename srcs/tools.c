/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:05:00 by akremer           #+#    #+#             */
/*   Updated: 2021/11/18 16:05:30 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			print(char *ptr)
{
	write(1, ptr, strlen(ptr));
}

void			print_macro_allo(void)
{
	printf("TINY_HEAP_ALLOCATION_SIZE = %ld\n", TINY_HEAP_ALLOCATION_SIZE);
	printf("SMALL_HEAP_ALLOCATION_SIZE = %ld\n", SMALL_HEAP_ALLOCATION_SIZE);
	printf("TINY_BLOCK_SIZE = %ld\n", TINY_BLOCK_SIZE);
	printf("SMALL_BLOCK_SIZE = %ld\n", SMALL_BLOCK_SIZE);
}