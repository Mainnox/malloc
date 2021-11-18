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

void		*realloc(void *ptr, size_t size)
{
	void		*ret;
	t_block		*s;

	s = NULL;
	ret = NULL;
	ret = malloc(size);
	if (ret && ptr)
	{
		s = (t_block *)(ptr - (sizeof(t_block)));
		if (s->data_size <= size)
			ft_strncpy(ret, ptr, s->data_size);
		else
			ft_strncpy(ret, ptr, size);
	}
	free(ptr);
	return (ret);
}
