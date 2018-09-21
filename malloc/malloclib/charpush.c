/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charpush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 17:35:17 by angonyam          #+#    #+#             */
/*   Updated: 2018/06/22 17:36:37 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloclib.h"
#include <sys/mman.h>

char		*charpush(char *str, char c)
{
	int		size;
	int		i;
	char	*newchar;
	int		j;

	size = ft_strlen(str);
	newchar = (char*)mmap(0, size + 2, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	newchar[0] = c;
	i = 1;
	j = 0;
	while (str[j])
	{
		newchar[i] = str[j];
		i++;
		j++;
	}
	newchar[i] = '\0';
	return (newchar);
}
