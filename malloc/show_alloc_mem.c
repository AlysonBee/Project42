/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 14:16:00 by angonyam          #+#    #+#             */
/*   Updated: 2018/06/29 15:54:02 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		show_alloc_mem(void)
{
	if (ft_strchr(g_info.tiny_block, 'T'))
	{
		tiny_small_large('T');
		decode(g_info.tiny_block, 'T',
				g_info.tiny.tiny_space_ptr);
	}
	if (ft_strchr(g_info.small_block, 'S'))
	{
		tiny_small_large('S');
		decode(g_info.small_block, 'S',
				g_info.small.small_space_ptr);
	}
	if (ft_strchr(g_info.large_block, 'L'))
	{
		tiny_small_large('L');
		decode(g_info.large_block, 'L',
				g_info.large.large_space_ptr);
	}
	ft_putstr("Total: ");
	put_n((size_t)g_info.total);
	g_info.total = 0;
}
