/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 18:45:22 by angonyam          #+#    #+#             */
/*   Updated: 2017/09/18 15:29:00 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../libft/libft.h"
#include <sys/wait.h>
#include <dirent.h>
#include <sys/types.h>

static int			run_command(char **directory, char **arguments,
	int i, char **environment)
{
	char	*temp;
	char	*executable;

	temp = ft_strjoin(directory[i], "/");
	executable = ft_strjoin(temp, arguments[0]);
	free(temp);
	ft_delarray((void**)directory);
	if (access(executable, X_OK) == -1)
	{
		ft_delarray((void**)directory);
		free(executable);
		return (-1);
	}
	execve(executable, arguments, environment);
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
	ft_delarray((void**)directory);
	return (-2);
}

static int			get_path(char **arguments, char **environment)
{
	int		i;
	char	*path;

	i = 0;
	while (environment[i])
	{
		if (ft_strncmp(environment[i], "PATH=", 5) == 0)
		{
			path = ft_strchr(environment[i], '=');
			path++;
			return (executing(path, environment, arguments));
		}
		i++;
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
			if (execve(args[0], args, environment) == -1)
			{
				ft_putstr(args[0]);
				if (args[0][0] != '\n')
					ft_putendl(" : command not found\n");
				ft_delarray((void**)args);
				exit(1);
			}
		}
		else
			ft_delarray((void**)args);
		exit(1);
	}
	ft_delarray((void**)args);
	wait(&pid);
	return (environment);
}
