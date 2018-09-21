/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_string_segment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 17:34:04 by angonyam          #+#    #+#             */
/*   Updated: 2018/06/22 17:34:51 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "malloclib.h"

char		*delete_segment(int start, int end, char *str)
{
	char	*newstr;
	int		size;
	int		i;
	int		j;

	size = strlen(str) - (end - start) + 1;
	newstr = (char*)mmap(0, size, PROT_READ | PROT_WRITE,
				MAP_ANON | MAP_PRIVATE, -1, 0);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (i == start)
		{
			while (i != end)
				i++;
			continue ;
		}
		newstr[j] = str[i];
		i++;
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}
