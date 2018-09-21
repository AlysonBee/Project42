/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:33:52 by angonyam          #+#    #+#             */
/*   Updated: 2018/06/29 16:01:14 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void					*error(void)
{
	return (NULL);
}

void					*adjust_pointer(unsigned long size)
{
	void				*ptr;
	extern t_malloc		g_info;

	if ((int)size < TINY_SIZE)
	{
		ptr = g_info.tiny.tiny_trav;
		g_info.tiny.tiny_trav += size;
		write_memory_record(size, g_info.tiny_block);
	}
	else if ((int)size > TINY_SIZE && (int)size <= SMALL_SIZE)
	{
		ptr = g_info.small.small_trav;
		g_info.small.small_trav += size;
		write_memory_record(size, g_info.small_block);
	}
	else
		ptr = NULL;
	return (ptr);
}

unsigned long long		limit_setter(void)
{
	struct rlimit		limit;

	getrlimit(RLIMIT_FSIZE, &limit);
	return (limit.rlim_max);
}

void					resize_tiny_small(void)
{
	extern t_malloc		g_info;

	if (g_info.tiny_malloc <= 0)
	{
		munmap(g_info.tiny.tiny_space_ptr,
				g_info.tiny_malloc);
		g_info.tiny = tiny_memory_alloc();
	}
	if (g_info.small_malloc <= 0)
	{
		munmap(g_info.small.small_space_ptr,
				g_info.small_malloc);
		g_info.small = small_memory_alloc();
	}
}

void					*malloc(size_t size)
{
	extern t_malloc		g_info;

	g_info.free_size_val = size;
	g_info.memory_used += size;
	if (g_info.flag == 0)
	{
		g_info.tiny = tiny_memory_alloc();
		g_info.small = small_memory_alloc();
		g_info.flag = 1;
		g_info.max = limit_setter();
	}
	if ((unsigned long long)g_info.memory_used >= g_info.max)
		return (error());
	if ((int)size <= SMALL_SIZE)
		g_info.main_ptr = adjust_pointer(size);
	else
	{
		g_info.large = large_memory_alloc(size);
		g_info.main_ptr = g_info.large.large_trav;
		g_info.large.large_trav += size;
		write_memory_record(size, g_info.large_block);
	}
	return (g_info.main_ptr);
}
