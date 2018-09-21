/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 17:28:47 by angonyam          #+#    #+#             */
/*   Updated: 2018/06/23 13:10:31 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloclib.h"
#include <sys/mman.h>

char		*itoa_no_malloc(int num)
{
	char	c;
	char	*v;
	int		size;

	size = number_length(num);
	v = (char*)mmap(0, size + 1, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	v[size] = '\0';
	size--;
	while (num > 0)
	{
		c = num % 10 + '0';
		v[size] = c;
		size--;
		num /= 10;
	}
	return (v);
}
