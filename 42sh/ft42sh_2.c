/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh-2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 06:53:37 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 17:18:13 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		**mul_function(char *comm)
{
	int		i;
	char	*ag;
	char	**args;
	char	*new;

	ag = (char*)malloc(sizeof(char) * ft_strlen(comm));
	i = 0;
	while (comm[i] && comm[i] != '\n')
	{
		ag[i] = comm[i];
		i++;
	}
	ag[i] = '\0';
	new = ft_strdup(ag);
	free(ag);
	new = handling_setenv_string(new);
	args = ft_strsplit(new, ' ');
	free(new);
	return (args);
}

char		**single_command(char *ting, char **env, int *val)
{
	char	*comm;

	comm = ft_strtrim(ting);
	if (wordcount(comm) > 0)
		comm = ag_function(comm);
	if (ft_strcmp(comm, "cd") == 0)
		env = ft_cd(env, NULL, val);
	else if (ft_strncmp(comm, "env", 3) == 0 || ft_strcmp(comm, "env") == 0)
		ft_env(env, val);
	else if (ft_strcmp(comm, "setenv") == 0 || ft_strcmp(comm, "unsetenv") == 0)
	{
		ft_printf("Usage : %s <env to adjust>\n", comm);
		*val = -1;
	}
	else if (ft_strcmp(comm, "echo") == 0)
		ft_printf("\n");
	else
		*val = -1;
	free(comm);
	return (env);
}

char		**multiple_commands(char *comm, char **env, int *val)
{
	char	**args;
	int		tag;

	tag = 0;
	args = mul_function(comm);
	if (ft_strcmp(args[0], "cd") == 0)
	{
		env = ft_cd(env, args[1], val);
		*val = 1;
	}
	else if (ft_strcmp(args[0], "setenv") == 0)
		env = ft_setenv(env, args[1], val);
	else if (ft_strcmp(args[0], "unsetenv") == 0)
		env = ft_unsetenv(env, args[1], val);
	else
		*val = -1;
	if (*val != -1)
		*val = 1;
	free_2d_array((void**)args);
	return (env);
}

char		**builtins(char **env, char *line, int *val)
{
	char	*comm;

	comm = ft_strtrim(line);
	if (!ft_strchr(comm, ' '))
		env = single_command(comm, env, val);
	else
		env = multiple_commands(comm, env, val);
	free(comm);
	return (env);
}

char		**run(char *str, char **env, int *val)
{
	char	**arr;

	env = builtins(env, str, val);
	if (*val <= 0)
	{
		arr = ft_strsplit(str, ' ');
		process(str, env, val);
		free_2d_array((void**)arr);
	}
	return (env);
}
