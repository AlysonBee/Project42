/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 17:28:03 by angonyam          #+#    #+#             */
/*   Updated: 2018/06/23 13:10:53 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloclib.h"
#include <sys/mman.h>
#include <stdio.h>

int		*update_memory_record(char *str)
{
	int		*start_end;
	int		last;

	start_end = (int*)mmap(0, 8, PROT_READ | PROT_WRITE, MAP_ANON |
			MAP_PRIVATE, -1, 0);
	last = ft_strlen(str) - 1;
	start_end[1] = last;
	while (last > 0)
	{
		if (!ft_isdigit(str[last]))
		{
			start_end[0] = last;
			break ;
		}
		last--;
	}
	return (start_end);
}
