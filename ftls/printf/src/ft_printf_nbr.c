/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 23:44:15 by angonyam          #+#    #+#             */
/*   Updated: 2017/10/06 23:44:18 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*conv_dec(uintmax_t nbr, int *nbr_digits)
{
	return (get_nbr_unsigned(nbr, nbr_digits, 10));
}

static int	signed_nbr(va_list ap, t_attr *attr)
{
	int		len;

	len = 0;
	if (attr->flags & J || attr->flags & Z)
		len = format_signed(va_arg(ap, intmax_t), attr);
	else if (attr->flags & LL)
		len = format_signed(va_arg(ap, long long), attr);
	else if (attr->flags & L || attr->flags & UPP_D_BIT)
		len = format_signed(va_arg(ap, long), attr);
	else if (attr->flags & HH)
		len = format_signed((char)va_arg(ap, int), attr);
	else if (attr->flags & H)
		len = format_signed((short)va_arg(ap, int), attr);
	else
		len = format_signed(va_arg(ap, int), attr);
	return (len);
}

static int	unsigned_nbr(va_list ap, t_attr *attr)
{
	int		len;

	len = 0;
	if (attr->flags & J)
		len = format_unsigned(va_arg(ap, uintmax_t), attr, &conv_dec);
	else if (attr->flags & Z)
		len = format_unsigned(va_arg(ap, size_t), attr, &conv_dec);
	else if (attr->flags & LL)
		len = format_unsigned(va_arg(ap, unsigned long long), attr,
			&conv_dec);
	else if (attr->flags & L || attr->flags & UPP_U_BIT)
		len = format_unsigned(va_arg(ap, unsigned long), attr, &conv_dec);
	else if (attr->flags & HH)
		len = format_unsigned((unsigned char)va_arg(ap, unsigned int), attr,
			&conv_dec);
	else if (attr->flags & H)
		len = format_unsigned((unsigned short)va_arg(ap, unsigned int), attr,
			&conv_dec);
	else
		len = format_unsigned(va_arg(ap, unsigned int), attr, &conv_dec);
	return (len);
}

int			print_decimal(va_list ap, t_attr *attr)
{
	int		len;
	int		flags;

	len = 0;
	flags = attr->flags;
	if (flags & LOW_D_BIT || flags & LOW_I_BIT || flags & UPP_D_BIT)
		len = signed_nbr(ap, attr);
	if (flags & LOW_U_BIT || flags & UPP_U_BIT)
		len = unsigned_nbr(ap, attr);
	return (len);
}
