/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 18:45:22 by angonyam          #+#    #+#             */
/*   Updated: 2017/11/19 13:06:40 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"
#include <sys/wait.h>
#include <dirent.h>
#include <sys/types.h>

static int			run_command(char **directory, char **arguments,
	int i, char **environment)
{
	char	*temp;
	char	*executable;
	extern char **environ;

	temp = ft_strjoin(directory[i], "/");
	executable = ft_strjoin(temp, arguments[0]);
	free(temp);
	free_2d_array((void**)directory);
	if (access(executable, X_OK) == -1)
	{
		free_2d_array((void**)directory);
		free(executable);
		return (-1);
	}
	execve(executable, arguments, environ);
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

static int			get_path(char **arguments, char **environment)
{
	int		i;
	char	*path;
	char	**env;

	i = -1;
	while (environment[++i])
	{
		if (ft_strlen(environment[i]) == 0)
			continue ;
		env = ft_strsplit(environment[i], '=');
		if (ft_strcmp(env[0], "PATH") == 0)
		{
			path = ft_strchr(environment[i], '=');
			path++;
			return (executing(env[1], environment, arguments));
		}
		free_2d_array((void**)env);
	}
	return (-2);
}

char				**process(char *line, char **environment)
{
	pid_t		pid;
	char		**args;

	args = ft_strsplit(line, ' ');
	pid = fork();
	if (pid == 0)
	{
		if (get_path(args, environment) == -2)
		{
			ft_printf("args[0] is %s\nit's size is ~%d\n", args[0], ft_strlen(args[0]));
			if (execve(args[0], args, NULL) == -1)
			{
				ft_putstr(args[0]);
				if (args[0][0] != '\n')
					ft_putendl(" : command not found\n");
				free_2d_array((void**)args);
			}
			exit(1);
		}
		else
			free_2d_array((void**)args);
		exit(1);
	}
	free_2d_array((void**)args);
	wait(&pid);
	return (environment);
}

int			main(int argc, char **argv, char **envp)
{
	int		i;
	char	**new;
	char	*str;

	i = 0;
	new = ft_arraydup(envp);
	while (new[i])
	{
		ft_printf("env is %s\n", new[i]);
		i++;
	}
	while (1)
	{
		str = (char*)malloc(sizeof(char) * 1000);
		if (ft_strstr(str, "exit"))
			break ;
		read(0, str, 1000);
		str = ft_strtrim(str);
		process(str, new);
		free(str);
	}
	free(str);
	free_2d_array((void**)new);
	return (0);
}




