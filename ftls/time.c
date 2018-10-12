/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 06:59:13 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/04 15:56:07 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**time_sort(char **array)
{
	struct stat		a;
	struct stat		b;
	int				i;
	int				j;
	char			*temp;

	i = 0;
	while (i++ < ft_arraylen(array))
	{
		j = -1;
		while (++j < ft_arraylen(array))
			if (array[j])
				if (!(lstat(array[j], &a) < 0 || lstat(array[j + 1], &b) < 0))
				{
					if (a.st_mtime < b.st_mtime)
					{
						temp = array[j];
						array[j] = array[j + 1];
						array[j + 1] = temp;
					}
				}
		j = 0;
	}
	return (array);
}
