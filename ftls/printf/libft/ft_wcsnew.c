/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 07:33:42 by jaleman           #+#    #+#             */
/*   Updated: 2017/02/19 07:33:42 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wcsnew(size_t size)
{
	wchar_t	*wcs;

	wcs = ft_memalloc(sizeof(wchar_t) * size + sizeof(wchar_t));
	return (wcs);
}
