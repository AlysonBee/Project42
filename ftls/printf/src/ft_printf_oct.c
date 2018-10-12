/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 23:46:33 by angonyam          #+#    #+#             */
/*   Updated: 2017/10/06 23:46:35 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*convert_octal(uintmax_t nbr, int *nbdig)
{
	return (get_nbr_unsigned(nbr, nbdig, 8));
}

int			print_octal(va_list ap, t_attr *attr)
{
	int		len;

	if (attr->flags & J)
		len = format_unsigned(va_arg(ap, uintmax_t), attr, &convert_octal);
	else if (attr->flags & Z)
		len = format_unsigned(va_arg(ap, size_t), attr, &convert_octal);
	else if (attr->flags & LL)
		len = format_unsigned(va_arg(ap, unsigned long long), attr, \
								&convert_octal);
	else if (attr->flags & L || attr->flags & UPP_O_BIT)
		len = format_unsigned(va_arg(ap, unsigned long), attr, &convert_octal);
	else if (attr->flags & H)
		len = format_unsigned((unsigned short)va_arg(ap, unsigned int), attr,
			&convert_octal);
	else if (attr->flags & HH)
		len = format_unsigned((unsigned char)va_arg(ap, unsigned int), attr,
			&convert_octal);
	else
		len = format_unsigned(va_arg(ap, unsigned int), attr, &convert_octal);
	return (len);
}
