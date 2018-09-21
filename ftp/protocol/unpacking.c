/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unpacking.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:22:21 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/31 07:22:22 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftp.h"

char			*unpack(char buffer[])
{
	size_t		i;
	size_t		j;
	char		*str;

	str = (char*)malloc(sizeof(char) * ft_atoi(buffer) + 1);
	i = 0;
	while (ft_isprint(buffer[i]))
		i++;
	i += 4;
	j = 0;
	while (j < (size_t)ft_atoi(buffer))
	{
		str[j] = buffer[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
