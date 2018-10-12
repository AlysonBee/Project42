/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 23:45:54 by angonyam          #+#    #+#             */
/*   Updated: 2017/10/06 23:45:56 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

int		print_spaces(int width, int len, int attr)
{
	while ((width - len) > 0)
	{
		ft_putchar(((attr & ZERO) && !(attr & MINUS)) ? '0' : ' ');
		len += 1;
	}
	return (len);
}

int		print_wide_string(va_list ap, t_attr *attr)
{
	int		len;
	wchar_t	*str;

	if (!(str = va_arg(ap, wchar_t *)))
		str = ft_wcsdup(L"(null)");
	len = ft_wcslen(str);
	if (!(attr->flags & MINUS))
		len = print_spaces(attr->width, len, attr->flags);
	ft_putwstr(str);
	if (attr->flags & MINUS)
		len = print_spaces(attr->width, len, attr->flags);
	return (len);
}

int		print_wide_character(va_list ap, t_attr *attr)
{
	int		len;
	wchar_t	c;

	c = va_arg(ap, wint_t);
	len = ft_wclen(c);
	if (!(attr->flags & MINUS))
		len = print_spaces(attr->width, len, attr->flags);
	ft_putwchar(c);
	if (attr->flags & MINUS)
		len = print_spaces(attr->width, len, attr->flags);
	return (len);
}

int		print_string(va_list ap, t_attr *attr)
{
	int		len;
	char	*str;

	if (attr->flags & L)
		return (print_wide_string(ap, attr));
	if (!(str = va_arg(ap, char *)))
		str = ft_strdup("(null)");
	len = ft_strlen(str);
	if (!(attr->flags & MINUS))
		len = print_spaces(attr->width, len, attr->flags);
	ft_putstr(str);
	if (attr->flags & MINUS)
		len = print_spaces(attr->width, len, attr->flags);
	return (len);
}

int		print_character(va_list ap, t_attr *attr)
{
	int		len;
	char	c;

	if (attr->flags & L)
		return (print_wide_character(ap, attr));
	c = va_arg(ap, int);
	len = sizeof(char);
	if (!(attr->flags & MINUS))
		len = print_spaces(attr->width, len, attr->flags);
	ft_putchar(c);
	if (attr->flags & MINUS)
		len = print_spaces(attr->width, len, attr->flags);
	return (len);
}
