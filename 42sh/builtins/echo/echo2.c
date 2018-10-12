/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 08:07:43 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 17:09:19 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../shell.h"

int			whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' ||
			c == '\n' || c == '\f');
}

int			print(char *str, char **env)
{
	int		i;
	char	*chr;
	char	**new;
	int		len;

	len = 0;
	chr = NULL;
	i = 0;
	while (env[i])
	{
		new = ft_strsplit(env[i], '=');
		if (strncmp(str, new[0], ft_strlen(new[0])) == 0)
		{
			len = ft_strlen(new[0]);
			chr = ft_strchr(env[i], '=');
			free_2d_array((void**)new);
			chr++;
			break ;
		}
		free_2d_array((void**)new);
		i++;
	}
	chr == NULL ? ft_printf(" ") : ft_printf("%s", chr);
	return (len);
}

int			enviroprint(char *str, char **env)
{
	print(str, env);
	return (1);
}

int			quotes(char *str, int i, int f)
{
	char	flag;
	int		j;

	j = 0;
	flag = (f == 1 ? '\'' : '\"');
	i++;
	while (str[i])
	{
		if (str[i] == flag)
		{
			j += 2;
			break ;
		}
		else if (str[i] == '$' && (flag == '\"' || flag == '\''))
			j += 2;
		else
			ft_printf("%c", str[i]);
		i++;
		j++;
	}
	ft_printf("\n");
	if (!ft_strchr(&str[i], '$') && !ft_strchr(&str[i], '\'')
			&& !ft_strchr(&str[i], '\"'))
		return (-1);
	return (j);
}

char		*remove_tabs(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			str[i] = ' ';
		i++;
	}
	return (str);
}
