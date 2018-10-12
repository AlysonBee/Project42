/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 23:48:32 by angonyam          #+#    #+#             */
/*   Updated: 2017/10/06 23:48:34 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wcsdup(wchar_t *src)
{
	int		len;
	wchar_t	*dst;

	len = ft_wcslen(src) + sizeof(wchar_t);
	dst = ft_memalloc(sizeof(wchar_t) * len);
	if (dst)
		ft_wcscpy(dst, src);
	return (dst);
}
