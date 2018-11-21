/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsferopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 11:10:35 by gsferopo          #+#    #+#             */
/*   Updated: 2017/09/04 11:21:16 by gsferopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(int value, int base)
{
	char	*tab;
	char	*s;
	int		len;
	int		n;

	n = value;
	if (n == 0)
		return ("0");
	tab = "0123456789ABCDEF";
	len = ft_numblen(ft_abs(n), base);
	if (base == 10 && n < 0)
	{
		len++;
		n *= -1;
	}
	s = (char *)malloc(len + 1);
	s[len] = '\0';
	while (n != 0 && len-- > -1)
	{
		s[len] = tab[ft_abs(n % base)];
		n /= base;
	}
	if (len != 0)
		s[0] = '-';
	return (s);
}
