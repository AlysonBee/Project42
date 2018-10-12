/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backquotes4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 13:02:18 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 16:53:07 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

char		*org(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	return (str);
}

char		*backquotes(char *line, char **env, int *val)
{
	char	*str;
	char	*new;
	int		j;

	str = ft_strchr(line, '`');
	j = last_quote(str, 2);
	new = ft_strsub(str, 1, j - 1);
	return (single_str(new, env, val));
}
