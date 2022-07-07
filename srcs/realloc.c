/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akremer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:23:40 by akremer           #+#    #+#             */
/*   Updated: 2021/11/18 17:45:24 by akremer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern t_heap *g_heap;

static int	checkptr(void *ptr) {
	t_heap *heap;

	if (ptr == NULL)
		return (1);
	heap = findheap((t_block **)&ptr);
	if (heap == NULL)
		return (0);
	if (findblock(heap, ptr) == NULL)
		return (0);
	return (1);
}

void		*realloc(void *ptr, size_t size)
{
	void		*ret;

	if (!checkptr(ptr))
		return (NULL);
	ret = NULL;
	ret = malloc(size);
	if (ret && ptr)
		ft_strncpy(ret, ptr, ft_strlen(ptr));
	free(ptr);
	return (ret);
}
