/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:26:16 by akremer           #+#    #+#             */
/*   Updated: 2021/06/24 16:57:42 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		main()
{
	printf("getpagesize = %d\n", getpagesize());
	printf("[size tiny]\n1 = %d\n2 = %d\n\n[size small]\n1 = %d\n2 = %d\n", TINY_HEAP_ALLOCATION_SIZE, TINY_BLOCK_SIZE, SMALL_HEAP_ALLOCATION_SIZE, SMALL_BLOCK_SIZE);
	for (int i = 0; i < 4; i++)
		if (malloc(10))
			break ;
	return (0);
}
