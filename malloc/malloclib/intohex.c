/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intohex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 17:30:47 by angonyam          #+#    #+#             */
/*   Updated: 2018/06/23 13:10:22 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloclib.h"

int			hexlength(size_t number)
{
	int				length;

	length = 0;
	while (number > 0)
	{
		number /= 16;
		length++;
	}
	return (length);
}

void		int_to_hex(size_t number)
{
	static char		hexadecimal[] = "0123456789abcdef";
	int				c;
	char			str[hexlength(number)];
	int				size;

	size = hexlength(number);
	str[size] = '\0';
	size--;
	while (number > 0)
	{
		c = number % 16;
		str[size] = hexadecimal[c];
		size--;
		number /= 16;
	}
	ft_putstr("0x");
	ft_putstr(str);
}
