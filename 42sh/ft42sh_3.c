/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh-3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 07:00:45 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 07:20:32 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <fcntl.h>

char		*stop_block(char *str, int *t)
{
	char	*new;
	int		i;

	new = (char*)ft_memalloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	while (str[i] != '=')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '=';
	i++;
	*t = i;
	return (new);
}

char		*handling_setenv_string(char *str)
{
	int		i;
	int		j;
	char	*target;
	char	*new;
	char	*ret;

	target = ft_strchr(str, '=');
	if (!target)
		return (str);
	if (target[1] == ' ')
	{
		new = stop_block(str, &i);
		j = 1;
		while (target[1 + j])
		{
			if (target[1 + j] == ' ')
				target[1 + j] = '^';
			j++;
		}
		ret = ft_strjoin(new, &target[2]);
		free(new);
		free(str);
		return (ret);
	}
	return (str);
}

int			logical_op_count(char *str)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == '|' && str[i + 1] == '|') ||
				(str[i] == '&' && str[i + 1] == '&'))
			count++;
		i++;
	}
	return (count);
}

char		**redirect(char **env, char *line, int *val, char *file)
{
	int		fd;
	int		save;
	char	*test;
	char	**to_pass;

	test = ft_strchr(line, '>');
	if (test[1] == '>')
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	to_pass = ft_strsplit(line, '>');
	save = dup(1);
	dup2(fd, 1);
	if (ft_strchr(to_pass[0], '|') && !ft_strstr(to_pass[0], "||"))
		piping(to_pass[0], env, val, val);
	else
	{
		if (ft_strstr(line, "echo"))
			aly_echo(to_pass[0], env, val);
		else
			env = run(to_pass[0], env, val);
	}
	dup2(save, 1);
	free_2d_array((void**)to_pass);
	return (env);
}

char		**run_redirection(char *str, char **env, int *val, int *r)
{
	char	*filename;
	char	*actual;
	int		j;

	*r = 1;
	filename = ft_strchr(str, '>');
	while (!ft_isalnum(filename[0]))
	{
		if (filename[0] == '/')
			break ;
		filename++;
	}
	j = 0;
	while (filename[j] != ' ' && filename[j])
		j++;
	actual = ft_strsub(filename, 0, j);
	env = redirect(env, str, val, actual);
	free(actual);
	return (env);
}
