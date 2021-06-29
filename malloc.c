/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 10:45:05 by akremer           #+#    #+#             */
/*   Updated: 2021/06/29 10:49:19 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"


static char	taketype(size_t size)
{
	char ret;

	if (size <= TINY_BLOCK_SIZE)
		ret = TINY;
	else if (size <= SMALL_BLOCK_SIZE)
		ret = SMALL;
	else
		ret = LARGE;
	return (ret);
}

void		*malloc(size_t size)
{
	char	type = taketype(size);
	t_heap	*act_page;

	if (!g_heap)
	{
		g_heap = createnewheap(size, type);
		act_page = g_heap;
	}
	else
	{
		act_page = checkifheapmatch(type);
		if (!act_page)
		{
			t_heap *first = createnewheap(size, type);
			first->next = g_heap;
			act_page = first;
			g_heap = first;
		}
	}
	return (createnewblock(act_page, size, type));
}
