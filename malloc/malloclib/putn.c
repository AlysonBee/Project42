/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 15:41:57 by angonyam          #+#    #+#             */
/*   Updated: 2018/06/23 15:42:37 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloclib.h"

void		put_n(size_t n)
{
	char	num[number_length(n)];
	int		size;
	int		c;

	size = number_length(n);
	num[size] = '\0';
	size--;
	while (n != 0)
	{
		c = n % 10 + '0';
		num[size] = c;
		n /= 10;
		size--;
	}
	ft_putstr(num);
}
