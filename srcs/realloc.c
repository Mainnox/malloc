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

	ret = NULL;
	ret = malloc(size);
	if (ret && ptr)
		ft_strncpy(ret, ptr, ft_strlen(ptr));
	free(ptr);
	return (ret);
}
