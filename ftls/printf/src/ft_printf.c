/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 23:36:42 by angonyam          #+#    #+#             */
/*   Updated: 2017/10/06 23:43:43 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	print_no_specifier(char c, t_attr *attr)
{
	int		len;

	if (!(attr->flags & MINUS))
		len = print_spaces(attr->width, sizeof(char), attr->flags);
	ft_putchar(c);
	if (attr->flags & MINUS)
		len = print_spaces(attr->width, sizeof(char), attr->flags);
	return (len);
}

static int	print_specifier(char format, va_list arg, t_attr *attr, int i)
{
	int		print;

	if (i == LOWER_S)
		print = print_string(arg, attr);
	else if (i == UPPER_S)
		print = print_wide_string(arg, attr);
	else if ((i == LOWER_D || i == UPPER_D || i == LOWER_I) \
				|| (i == LOWER_U || i == UPPER_U))
		print = print_decimal(arg, attr);
	else if (i == LOWER_O || i == UPPER_O)
		print = print_octal(arg, attr);
	else if (i == LOWER_P || i == LOWER_X || i == UPPER_X)
		print = print_hexadecimal(arg, attr);
	else if (i == LOWER_C)
		print = print_character(arg, attr);
	else if (i == UPPER_C)
		print = print_wide_character(arg, attr);
	else if (i == LOWER_B)
		print = print_binary(arg, attr);
	else
		print = print_no_specifier(format, attr);
	return (print);
}

static int	print_stdout(const char *format[], va_list arg)
{
	int		specifier;
	t_attr	attribute;

	attribute.flags = 0;
	attribute.width = 0;
	attribute.precision = 0;
	specifier = parse_specifier(arg, (char **)format, &attribute);
	if (!**format)
		return (-1);
	return (print_specifier((char)**format, arg, &attribute, specifier));
}

int			ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	arg;

	count = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if ((i = print_stdout(&str, arg)) == PRINTF_FAILURE)
				break ;
			count += i;
		}
		else
		{
			ft_putchar(*str);
			count++;
		}
		str++;
	}
	va_end(arg);
	return (count);
}
