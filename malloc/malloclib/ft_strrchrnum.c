/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchrnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:42:54 by angonyam          #+#    #+#             */
/*   Updated: 2018/06/23 15:42:57 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloclib.h"

int		ft_strrchrnum(char *str, char c)
{
	int	i;
	int dist;

	dist = ft_strlen(str) - 1;
	i = 0;
	while (dist > 0)
	{
		if (str[dist] == c)
			return (dist);
		dist--;
	}
	return (0);
}
