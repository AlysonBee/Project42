/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 13:08:32 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 16:46:16 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>

static int			run_command(char **directory, char **arguments,
	int i, char **environment)
{
	char	*temp;
	char	*executable;
	int		val;

	temp = ft_strjoin(directory[i], "/");
	executable = ft_strjoin(temp, arguments[0]);
	free(temp);
	free_2d_array((void**)directory);
	val = execve(executable, arguments, environment);
	free(executable);
	return (1);
}

static int			executing(char *path, char **environment, char **arguments)
{
	char			**directory;
	DIR				*dp;
	struct dirent	*file;
	int				i;

	directory = ft_strsplit(path, ':');
	i = 0;
	while (directory[i])
	{
		if (!(dp = opendir(directory[i])))
			break ;
		while ((file = readdir(dp)))
		{
			if (ft_strcmp(file->d_name, arguments[0]) == 0)
				return (run_command(directory, arguments, i, environment));
		}
		closedir(dp);
		i++;
	}
	free_2d_array((void**)directory);
	return (-2);
}

static int		get_path(char **args, char **env)
{
	int			i;
	char		**path;
	char		*test;

	i = -1;
	while (env[++i])
	{
		if (ft_strlen(env[i]) == 0)
			continue ;
		path = ft_strsplit(env[i], '=');
		if (ft_strcmp(path[0], "PATH") == 0)
		{
			test = ft_strdup(path[1]);
			free_2d_array((void**)path);
			return (executing(test, env, args));
		}
		free_2d_array((void**)path);
	}
	return (-2);
}

int				smallprocess(char *first, char **env,
		int *status, char **args_stuff)
{
	char		**args;
	int			ex_stat;

	ex_stat = 0;
	args_stuff = NULL;
	*status = 1;
	args = ft_strsplit(first, ' ');
	if (get_path(args, env) == -2)
		if (execve(first, args, env) == -1)
		{
			ft_printf("%s : command not found\n", args[0]);
			free_2d_array((void**)args);
		}
	return (ex_stat);
}
