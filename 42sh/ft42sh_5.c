/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh-5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 07:12:36 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 16:41:17 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*quote_trim(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			str[i] = ' ';
		i++;
	}
	if (ft_strchr(str, '\'') || ft_strchr(str, '\"'))
		return (quote_sanitization(str));
	return (whitespace_trim(str));
}

char		*working_with_c(char *str, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count % 2 == 0 ? quote_trim(str, c) : str);
}

char		*quote_sanitization(char *str)
{
	int		i;
	char	c;
	int		count;

	count = 0;
	c = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			break ;
		i++;
	}
	if (str[i])
		c = str[i];
	if (c)
		return (working_with_c(str, c));
	return (str);
}

int			export_check(char *str)
{
	char	**array;
	char	*target;

	target = ft_strtrim(str);
	if (ft_strchr(str, '='))
	{
		array = ft_strsplit(target, ' ');
		if (ft_strcmp(array[0], "setenv") == 0)
		{
			free(target);
			free_2d_array((void**)array);
			return (0);
		}
		free_2d_array((void**)array);
	}
	free(target);
	return (1);
}
