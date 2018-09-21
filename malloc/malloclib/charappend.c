/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charappend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 17:36:41 by angonyam          #+#    #+#             */
/*   Updated: 2018/06/22 18:38:27 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <sys/mman.h>

char		*charappend(char *str, char c)
{
	int		size;
	char	*newchar;
	int		i;

	size = strlen(str);
	newchar = (char*)mmap(0, size + 2, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	i = 0;
	while (str[i])
	{
		newchar[i] = str[i];
		i++;
	}
	newchar[i] = c;
	newchar[++i] = '\0';
	munmap(str, size);
	return (newchar);
}
