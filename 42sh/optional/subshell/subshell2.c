/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:23:34 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 17:00:57 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

char				*x_and_y(char *str, int x, int y)
{
	char			*ret;

	ret = ft_strsub(str, x, y - x);
	free(str);
	return (ret);
}

char				*check_subshell(char *str)
{
	int				i;
	int				x;
	int				y;

	x = 0;
	y = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '(')
			x = i;
		if (str[i] == ')' && x == 0)
		{
			ft_printf("42sh : parse error near `)'\n");
			return (NULL);
		}
		if (str[i] == ')')
			y = i;
		i++;
	}
	if (x && y)
		return (x_and_y(str, x, y));
	return (str);
}

char			*remove_newline(char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break ;
		}
		i++;
	}
	return (str);
}
