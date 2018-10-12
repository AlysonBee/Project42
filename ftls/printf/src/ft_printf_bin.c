/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 23:41:29 by angonyam          #+#    #+#             */
/*   Updated: 2017/10/06 23:41:32 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*convert_binary(uintmax_t nbr, int *nbr_digits)
{
	return (get_nbr_unsigned(nbr, nbr_digits, 2));
}

int			print_binary(va_list ap, t_attr *attr)
{
	int		len;

	if (attr->flags & J)
		len = format_unsigned(va_arg(ap, uintmax_t), attr, &convert_binary);
	else if (attr->flags & Z)
		len = format_unsigned(va_arg(ap, size_t), attr, &convert_binary);
	else if (attr->flags & LL)
		len = format_unsigned(va_arg(ap, unsigned long long), attr, \
								&convert_binary);
	else if (attr->flags & L || attr->flags & UPP_O_BIT)
		len = format_unsigned(va_arg(ap, unsigned long), attr, &convert_binary);
	else if (attr->flags & H)
		len = format_unsigned((unsigned short)va_arg(ap, unsigned int), attr,
			&convert_binary);
	else if (attr->flags & HH)
		len = format_unsigned((unsigned char)va_arg(ap, unsigned int), attr,
			&convert_binary);
	else
		len = format_unsigned(va_arg(ap, unsigned int), attr, &convert_binary);
	return (len);
}
