/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_functions_shared.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:22:11 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/31 07:22:12 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftp.h"

size_t			edit_len(unsigned char *message)
{
	size_t		size;

	size = number_len(ft_atoi((const char *)message)) + 4;
	return (size);
}

size_t			number_len(size_t number)
{
	size_t		size;

	size = 0;
	while (number > 0)
	{
		size++;
		number /= 10;
	}
	return (size);
}
