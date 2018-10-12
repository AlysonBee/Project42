/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 06:59:13 by angonyam          #+#    #+#             */
/*   Updated: 2017/10/24 07:08:59 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_charjoin(char *str, char c)
{
	int		i;
	char	*new;

	new = (char*)malloc(sizeof(char) * ft_strlen(str) + 2);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	new[++i] = '\0';
	return (new);
}

