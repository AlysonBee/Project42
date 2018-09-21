/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 16:05:42 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/01 09:16:01 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		tiny_small_large(char c)
{
	extern t_malloc		g_info;

	if (c == 'T')
	{
		write(1, "TINY : ", 7);
		int_to_hex((size_t)((int*)g_info.tiny.tiny_space_ptr));
		ft_putchar('\n');
	}
	else if (c == 'S')
	{
		write(1, "SMALL : ", 8);
		int_to_hex((size_t)((int*)g_info.small.small_space_ptr));
		ft_putchar('\n');
	}
	else if (c == 'L')
	{
		write(1, "LARGE : ", 8);
		int_to_hex((size_t)((int*)g_info.large.large_space_ptr));
		ft_putchar('\n');
	}
}

void		print_address_distance(int equation[], int ptr_num)
{
	int					dist;
	extern t_malloc		g_info;

	dist = equation[1] - equation[0];
	int_to_hex(ptr_num);
	ft_putstr(" - ");
	int_to_hex(ptr_num + equation[1]);
	ft_putstr(" : ");
	put_n(equation[1]);
	g_info.total += equation[1];
	ft_putchar('\n');
}

int			print_address(int equation[], int ptr_num,
			int *count)
{
	print_address_distance(equation, ptr_num);
	ptr_num += equation[1];
	*count = 0;
	return (ptr_num);
}
