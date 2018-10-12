/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backquotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 07:11:32 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 16:52:59 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

char		*align(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = ' ';
		i++;
	}
	return (str);
}

char		*running_out_of_function_names(char *s1, char *to_add)
{
	char	*temp;

	temp = ft_strjoin(s1, to_add);
	free(s1);
	free(to_add);
	return (temp);
}

char		*compress(char *sub)
{
	char	*new;
	int		i;
	int		j;

	i = ft_strlen(sub) - 1;
	new = (char*)ft_memalloc(sizeof(char) * ft_strlen(sub) + 2);
	while (i >= 0 && sub[i] != '`')
		i--;
	j = i;
	i = 0;
	while (sub[i])
	{
		if (i == j)
		{
			new[i] = '`';
			break ;
		}
		new[i] = sub[i];
		i++;
	}
	return (new);
}

char		*string_cleaning(char *line)
{
	char	*str;

	str = ft_strchr(line, '`');
	if (charcount(str, '`') % 2 != 0)
	{
		str = back_subshell(str);
		str = org(str);
	}
	return (str);
}

char		*recursive(char *line, char **env, int *val)
{
	char	*sub;
	char	*str;
	char	*ret;
	char	*new;
	int		j;

	ret = (char*)ft_memalloc(sizeof(char));
	str = string_cleaning(line);
	while (ft_strchr(str, '`'))
	{
		j = last_quote(str, 1);
		sub = ft_strsub(str, 0, j + 3);
		new = backquotes(sub, env, val);
		ret = running_out_of_function_names(ret, new);
		free(sub);
		str++;
		if (!(str = ft_strchr(str, '`')))
			break ;
		str++;
		if (!(str = ft_strchr(str, '`')))
			break ;
	}
	ret = align(ret);
	return (ret);
}
