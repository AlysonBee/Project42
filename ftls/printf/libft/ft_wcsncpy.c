/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 23:49:00 by angonyam          #+#    #+#             */
/*   Updated: 2017/10/06 23:49:02 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wcsncpy(wchar_t *dst, const wchar_t *src, size_t n)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (len < n)
	{
		len += ft_wclen(src[i]);
		if (len > n)
			break ;
		dst[i] = src[i];
		dst[++i] = L'\0';
	}
	return (dst);
}
