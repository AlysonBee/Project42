/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_alloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 17:08:40 by angonyam          #+#    #+#             */
/*   Updated: 2018/06/23 15:57:10 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_tiny_memory_space			tiny_memory_alloc(void)
{
	t_tiny_memory_space		tiny;
	extern t_malloc			g_info;

	g_info.tiny_malloc = TINY_SIZE * 5000;
	tiny.tiny_space_ptr = mmap(0, TINY_SIZE * 5000, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	tiny.tiny_space_used = 0;
	tiny.tiny_trav = tiny.tiny_space_ptr;
	return (tiny);
}

t_small_memory_space		small_memory_alloc(void)
{
	t_small_memory_space	small;
	extern t_malloc			g_info;

	g_info.small_malloc = SMALL_SIZE * 5000;
	small.small_space_ptr = mmap(0, SMALL_SIZE * 5000, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	small.small_trav = small.small_space_ptr;
	small.small_space_used = 0;
	return (small);
}

t_large_memory_space		large_memory_alloc(size_t size)
{
	t_large_memory_space	large;

	large.large_space_ptr = mmap(0, size, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	large.large_trav = large.large_space_ptr;
	return (large);
}
