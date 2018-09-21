/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:42:27 by angonyam          #+#    #+#             */
/*   Updated: 2018/06/29 16:00:57 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		rewrite_records(char current_info[], int c)
{
	int					distance;

	distance = ft_strrchrnum(current_info, c);
	current_info[distance] = '\0';
}

void		free(void *ptr)
{
	extern t_malloc		g_info;

	if ((int *)ptr == (int*)(g_info.tiny.tiny_trav - g_info.free_size_val))
	{
		ptr = g_info.tiny.tiny_trav;
		munmap(g_info.tiny.tiny_trav, g_info.free_size_val);
		g_info.tiny.tiny_trav = g_info.tiny.tiny_space_ptr;
		rewrite_records(g_info.tiny_block, 'T');
		g_info.tiny_malloc -= g_info.free_size_val;
	}
	else if ((int *)ptr ==
			(int*)(g_info.small.small_trav - g_info.free_size_val))
	{
		ptr = g_info.small.small_trav;
		munmap(g_info.small.small_space_ptr, g_info.free_size_val);
		g_info.small.small_trav = g_info.small.small_space_ptr;
		g_info.small_malloc -= g_info.free_size_val;
		rewrite_records(g_info.small_block, 'S');
	}
	else if (ptr)
	{
		munmap(ptr, g_info.free_size_val);
		rewrite_records(g_info.large_block, 'L');
	}
	g_info.memory_used -= g_info.free_size_val;
}
