/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 23:46:41 by angonyam          #+#    #+#             */
/*   Updated: 2017/10/06 23:46:45 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	not_decimal(uintmax_t nbr, int attr, int prec)
{
	if ((attr & LOW_O_BIT || attr & UPP_O_BIT) && attr & HASH \
			&& (nbr || (!nbr && attr & PRECISION && !prec)))
		return (1);
	else if (((attr & LOW_X_BIT || attr & UPP_X_BIT) && attr & HASH && nbr) \
				|| attr & LOW_P_BIT)
		return (2);
	return (0);
}

int			get_nbr_zeroes(t_attr *attr, int *len, int sign)
{
	int		nbr_zeros;

	nbr_zeros = 0;
	if (attr->flags & PRECISION && attr->precision > *len - sign)
	{
		nbr_zeros += attr->precision - *len + sign;
		*len += nbr_zeros;
	}
	if (attr->flags & WIDTH && attr->flags & ZERO && !(attr->flags & MINUS) \
		&& !(attr->flags & PRECISION) && attr->width > *len)
	{
		nbr_zeros += attr->width - *len;
		*len += nbr_zeros;
	}
	return (nbr_zeros);
}

int			get_nbr_spaces(int attr, int minw, int *len)
{
	int		nbr_spaces;

	nbr_spaces = 0;
	if (attr & WIDTH && (!(attr & ZERO) || attr & MINUS || attr & PRECISION) \
		&& minw > *len)
	{
		nbr_spaces += minw - *len;
		*len += nbr_spaces;
	}
	return (nbr_spaces);
}

char		*get_nbr_unsigned(uintmax_t nbr, int *nbr_digits, int base)
{
	int			len;
	char		*result;
	uintmax_t	reminder;

	len = 0;
	reminder = nbr;
	*nbr_digits = (!nbr) ? 1 : 0;
	while (reminder)
	{
		reminder /= base;
		*nbr_digits += 1;
	}
	if (!(result = (char *)malloc(sizeof(char) * (*nbr_digits))))
		return (NULL);
	*result = '0';
	len = (!nbr) ? 1 : 0;
	while (nbr)
	{
		reminder = nbr % base;
		nbr /= base;
		result[len++] = reminder + '0';
	}
	result[len] = '\0';
	result = ft_strrev(result);
	return (result);
}

int			format_unsigned(uintmax_t nbr, t_attr *attr, \
							char *(*convert)(uintmax_t, int *))
{
	int		len;
	int		sign;
	int		nbr_zeros;
	int		nbr_spaces;
	char	*nbr_converted;

	nbr_converted = convert(nbr, &len);
	sign = not_decimal(nbr, attr->flags, attr->precision);
	if (attr->flags & LOW_X_BIT || attr->flags & LOW_P_BIT)
		ft_str_to_lowcase(nbr_converted);
	(attr->flags & PRECISION && !attr->precision && !nbr) ? len = 0 : len;
	len += sign;
	nbr_zeros = get_nbr_zeroes(attr, &len, (sign == 2) ? 2 : 0);
	nbr_spaces = get_nbr_spaces(attr->flags, attr->width, &len);
	!(attr->flags & MINUS) ? ft_putnchar(' ', nbr_spaces) : 0;
	not_decimal(nbr, attr->flags, attr->precision) ? ft_putchar('0') : 0;
	if (not_decimal(nbr, attr->flags, attr->precision) > 1)
		attr->flags & UPP_X_BIT ? ft_putchar('X') : ft_putchar('x');
	ft_putnchar('0', nbr_zeros);
	if (!(attr->flags & PRECISION && !attr->precision && !nbr))
		ft_putstr(nbr_converted);
	free(nbr_converted);
	(attr->flags & MINUS) ? ft_putnchar(' ', nbr_spaces) : 0;
	return (len);
}
