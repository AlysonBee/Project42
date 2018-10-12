/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 23:49:11 by angonyam          #+#    #+#             */
/*   Updated: 2017/10/06 23:49:13 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwstr(wchar_t *wcs)
{
	int		len;

	len = 0;
	while (*wcs)
	{
		ft_putwchar(*wcs);
		len += ft_wclen(*wcs);
		wcs += 1;
	}
	return (len);
}
