/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:11:19 by angonyam          #+#    #+#             */
/*   Updated: 2018/06/29 16:02:27 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*realloc(void *ptr, size_t size)
{
	void					*newptr;
	int						if_fail;
	extern t_malloc			g_info;

	if (g_info.memory_used < 0)
		return (NULL);
	newptr = mmap(0, size, PROT_READ | PROT_WRITE,
				MAP_ANON | MAP_PRIVATE, -1, 0);
	if (newptr == MAP_FAILED)
	{
		if_fail = g_info.free_size_val;
		newptr = malloc(size);
		ft_memcpy(newptr, ptr, if_fail);
		free(ptr);
	}
	else
	{
		ft_memcpy(newptr, ptr, g_info.free_size_val);
		ft_memcpy(newptr + g_info.free_size_val, "\0", 1);
		munmap(ptr, g_info.free_size_val);
	}
	return (newptr);
}
