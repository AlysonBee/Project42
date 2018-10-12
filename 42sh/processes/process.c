/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 13:08:32 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 17:10:43 by angonyam         ###   ########.fr       */
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
	char			*temp;
	char			*executable;
	int				val;

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

static int			get_path(char **args, char **env)
{
	int				i;
	char			**path;
	char			*test;

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

char				*organize(char *first)
{
	char			*argu;
	int				i;

	argu = (char*)malloc(sizeof(char) * ft_strlen(first) + 2);
	i = 0;
	while (first[i])
	{
		if (first[i] == '\n')
		{
			argu[i] = '\0';
			break ;
		}
		argu[i] = first[i];
		i++;
	}
	return (argu);
}

int					process(char *first, char **env, int *status)
{
	char			**args;
	pid_t			pid;
	int				ex_stat;

	args = ft_strsplit(first, ' ');
	pid = fork();
	if (pid == 0)
	{
		if (get_path(args, env) == -2)
			if (execve(args[0], args, env) == -1)
			{
				ft_printf("%s : command not found\n", args[0]);
				free_2d_array((void**)args);
				exit(1);
			}
		exit(1);
	}
	free_2d_array((void**)args);
	wait(&pid);
	ex_stat = WEXITSTATUS(pid);
	*status = ex_stat == 0 ? 1 : -1;
	return (ex_stat);
}
