/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 09:51:03 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 09:55:18 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

char		*newline_trim(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			return (str);
		}
		i++;
	}
	return (str);
}

int			ev_size(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char		*remove_zeroes(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '^')
			str[i] = ' ';
		i++;
	}
	return (str);
}

char		*a_string(char *left, char *right, int *status)
{
	char	*temp;
	char	*new;

	*status = 1;
	temp = ft_strjoin(left, "=");
	if (ft_strchr(right, '^'))
	{
		right = remove_zeroes(right);
	}
	new = ft_strjoin(temp, right);
	free(temp);
	return (new);
}

char		**setenv_intro(char *line, int *status)
{
	char	**src;
	char	*to_set;

	line = remove_zeroes(line);
	to_set = newline_trim(line);
	src = ft_strsplit(to_set, '=');
	*status = -1;
	if (!ft_strchr(line, '='))
	{
		ft_printf("Usage: setenv VARIABLE=value\n");
		*status = 1;
		free_2d_array((void**)src);
		return (NULL);
	}
	return (src);
}
