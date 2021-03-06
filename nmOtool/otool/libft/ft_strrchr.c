/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:55:53 by angonyam          #+#    #+#             */
/*   Updated: 2017/05/31 15:38:13 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int count;

	if (c == '\0')
		return ((char*)s + ft_strlen(s));
	else
	{
		count = ft_strlen(s);
		count--;
		while (count >= 0)
		{
			if (s[count] == (char)c)
				return ((char*)s + count);
			count--;
		}
	}
	return (NULL);
}
