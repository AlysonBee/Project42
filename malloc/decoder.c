/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 17:02:50 by angonyam          #+#    #+#             */
/*   Updated: 2018/06/23 16:06:43 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>
#include <string.h>
#include "malloclib/malloclib.h"

/*
** 	Decode takes the string contents created by
**	write_memory_alloc and turns them into the
**	format needed for print-memory
*/

int			first_runthrough(void *map_ptr, char *memory_list, char c)
{
	int						val;
	char					*v;
	size_t					num;
	int						another;

	num = (size_t)((int*)map_ptr);
	v = ft_strchr(memory_list, c);
	val = ft_atoi(&v[1]);
	another = val;
	int_to_hex(num);
	ft_putstr(" - ");
	num += val;
	int_to_hex(num);
	ft_putstr(" : ");
	put_n(another);
	ft_putchar('\n');
	return (num);
}

int			reset_save_ptr(char *memory_list, void *tmp)
{
	int						equation;

	tmp = memory_list;
	memory_list++;
	if (!(equation = ft_atoi(memory_list)))
		return (-1);
	memory_list = memory_list + number_length(equation);
	return (1);
}

void		decode(char *memory_list, char c, void *map_ptr)
{
	int						i;
	int						save;
	int						ct;
	int						equation[2];
	extern t_malloc			g_info;

	g_info.ptr_number = first_runthrough(map_ptr, memory_list, c);
	i = 0;
	ct = 0;
	while (memory_list[i])
	{
		if (memory_list[i] == c)
		{
			save = i++;
			if (!(equation[ct] = ft_atoi(&memory_list[i])))
				continue ;
			i += number_length(equation[ct++]) - 1;
		}
		i++;
		if (ct == 2)
		{
			g_info.ptr_number = print_address(equation, g_info.ptr_number, &ct);
			i = save;
		}
	}
}
