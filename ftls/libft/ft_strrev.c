/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 06:47:51 by angonyam          #+#    #+#             */
/*   Updated: 2017/10/26 06:54:08 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char		*ft_strrev(char *str)
{
	char	temp;
	int		start;
	int		end;

	end = ft_strlen(str);
	start = -1;
	while (++start < --end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
	};
	return (str);
}
