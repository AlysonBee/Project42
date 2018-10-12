/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_attr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 23:41:41 by angonyam          #+#    #+#             */
/*   Updated: 2017/10/06 23:42:48 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	get_flags(char flg, t_attr *attr)
{
	flg == '#' ? attr->flags |= HASH : 0;
	flg == '0' ? attr->flags |= ZERO : 0;
	flg == '-' ? attr->flags |= MINUS : 0;
	flg == ' ' ? attr->flags |= SPACE : 0;
	flg == '+' ? attr->flags |= PLUS : 0;
	return (flg == '#' || flg == '0' || flg == '-' || flg == ' ' || flg == '+');
}

static int	get_width(va_list arg, char *format, t_attr *attr)
{
	int		width;
	char	*nbr;

	width = 0;
	if (format[width] == '*')
	{
		attr->width = va_arg(arg, int);
		if (attr->width < 0)
		{
			attr->width *= -1;
			attr->flags |= MINUS;
		}
		width = 1;
	}
	else
	{
		while (ft_isdigit(format[width]))
			width += 1;
		if (!width || !(nbr = ft_strsub(format, 0, width)))
			return (0);
		attr->width = ft_atoi(nbr);
		free(nbr);
	}
	return (width);
}

static int	get_precision(va_list ap, char *format, t_attr *attr)
{
	int		precision;
	char	*nbr;

	precision = 0;
	if (format[0] == '.')
	{
		precision = 1;
		if (format[precision] == '*')
		{
			attr->precision = va_arg(ap, int);
			precision += 1;
		}
		else
		{
			while (ft_isdigit(format[precision]))
				precision += 1;
			if (!(nbr = ft_strsub(format, 1, precision)))
				return (0);
			attr->precision = (precision != 1) ? ft_atoi(nbr) : 0;
			free(nbr);
		}
	}
	return (precision);
}

static int	get_length(char *format, t_attr *attr)
{
	int		length;

	length = 0;
	while (format[length] == 'h' || format[length] == 'l' \
			|| format[length] == 'j' || format[length] == 'z')
	{
		if (format[length] == 'h')
			format[length + 1] == 'h' \
				? (attr->flags |= HH) : (attr->flags |= H);
		if (format[length] == 'l')
			format[length + 1] == 'l' \
				? (attr->flags |= LL) : (attr->flags |= L);
		if (attr->flags == HH || attr->flags == LL)
			length += 1;
		if (format[length] == 'j')
			attr->flags |= J;
		if (format[length] == 'z')
			attr->flags |= Z;
		length += 1;
	}
	return (length);
}

int			get_attributes(char **format, va_list arg, t_attr *attr)
{
	char	*init;
	int		format_width;

	init = *format;
	while (get_flags(**format, attr))
		(*format)++;
	while ((format_width = get_width(arg, *format, attr)))
	{
		attr->flags |= WIDTH;
		(*format) += format_width;
	}
	while ((format_width = get_precision(arg, *format, attr)))
	{
		if (attr->precision >= 0)
			attr->flags |= PRECISION;
		(*format) += format_width;
	}
	while ((format_width = get_length(*format, attr)))
		(*format) += format_width;
	return (*format > init);
}
