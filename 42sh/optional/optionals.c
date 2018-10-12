/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optionals.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:25:07 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 17:03:36 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int			backtick_count(char *str)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '`')
			count++;
		i++;
	}
	return (count);
}

char		*final_cut(char *str)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (backtick_count(str) == 1)
		return (str);
	new = (char*)ft_memalloc(sizeof(char) * ft_strlen(str) + 2);
	while (str[i])
	{
		if (str[i] == '`')
		{
			new[j] = ' ';
			i++;
			while (str[i] != '`')
				i++;
		}
		else
			new[j] = str[i];
		i++;
		j++;
	}
	free(str);
	return (new);
}

char		*deconstruct(char *str)
{
	char	**lines;
	int		i;
	char	*command;
	char	*temp;

	command = ft_strnew(1);
	lines = ft_strsplit(str, ' ');
	i = 0;
	while (lines[i])
	{
		if (lines[i][0] == '`')
			break ;
		temp = ft_strjoin(command, lines[i]);
		free(command);
		command = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	free_2d_array((void**)lines);
	return (command);
}

char		*modified_string(char *str, char **env)
{
	char	*ln;
	int		val;
	char	*temp;
	char	*command;
	char	*ret;

	val = 0;
	ln = ft_strtrim(str);
	command = deconstruct(str);
	if (ft_strchr(ln, '`'))
	{
		free(ln);
		ln = recursive(str, env, &val);
		ln = final_cut(ln);
		ret = ft_strjoin(command, ln);
		free(command);
		free(ln);
		return (ret);
	}
	else if (ft_strchr(ln, '\'') || ft_strchr(ln, '\"'))
	{
		temp = ft_strchr(ln, '\'') ? ft_strchr(ln, '\'') : ft_strchr(ln, '\"');
		ln = inhibitor(ln, temp);
	}
	return (ln);
}

char		**optionals(char *str, char **env, int *val)
{
	t_exp	*head;

	if (wordcount_e(str) == 0 && ft_strchr(str, '='))
		env = export(str, env, &head, val);
	else if (ft_strchr(str, '(') && !ft_strchr(str, ')'))
		env = subshell(str, env, val);
	return (env);
}
