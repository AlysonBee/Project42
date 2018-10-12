/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 09:15:01 by angonyam          #+#    #+#             */
/*   Updated: 2017/10/24 09:17:43 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_numdup(int *array, int size, int to_add)
{
	int		*new;
	int		i;

	new = (int*)malloc(sizeof(int) * size + 2);
	i = 0;
	while (array[i])
	{
		new[i] = array[i];
		i++;
	}
	new[i] = to_add;
	new[++i] = -1;
	return (new);
}
