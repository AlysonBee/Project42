/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabs_to_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 12:39:25 by angonyam          #+#    #+#             */
/*   Updated: 2017/09/17 12:54:27 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"

char		*tabspace(char *str)
{
	char	*new;
	int		i;

	new = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			new[i] = ' ';
		else
			new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
