/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 17:01:06 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/04 08:05:47 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_arr(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		ft_printf("array is %s\n", array[i]);
		i++;
	}
}
