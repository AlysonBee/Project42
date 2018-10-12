/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 10:51:45 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/19 17:04:29 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

int				g_fd_in;
int				g_p[2];

void			execve_pipe(char ***cmd, char **env, int *val)
{
	pid_t		pid;
	char		**main_command;

	while (*cmd != NULL)
	{
		pipe(g_p);
		if ((pid = fork()) == 0)
		{
			dup2(g_fd_in, 0);
			if (*(cmd + 1) != NULL)
				dup2(g_p[1], 1);
			main_command = ft_strjoinarr(*cmd);
			local_process(main_command, val, env);
		}
		else
		{
			close(g_p[1]);
			g_fd_in = g_p[0];
			cmd++;
			wait(NULL);
		}
	}
	waitpid(pid, 0, 0);
}

int				exec_pipe(char **str, int len, char **env, int *val)
{
	char		***pipes;
	char		**temp_pipe;
	int			i;

	pipes = (char ***)ft_memalloc(sizeof(char **) * (len));
	i = -1;
	while (str[++i])
	{
		temp_pipe = ft_strsplit(str[i], ' ');
		pipes[i] = ft_strarrdup(temp_pipe);
		free_2d_array((void**)temp_pipe);
	}
	pipes[i] = NULL;
	execve_pipe(pipes, env, val);
	free_3d_array((void***)pipes);
	return (1);
}

char			*comma_strip(char *command)
{
	char		*new;
	int			i;
	int			j;

	j = 0;
	i = 0;
	new = (char*)malloc(sizeof(char) * ft_strlen(command) + 1);
	while (command[i])
	{
		if (command[i] == 39)
			;
		else
		{
			new[j] = command[i];
			j++;
		}
		i++;
	}
	new[j] = '\0';
	return (new);
}

int				pipe_parse(char *command, char **env, int *val)
{
	char		**temp_pipes;
	int			len;

	len = 0;
	g_fd_in = 0;
	temp_pipes = ft_strsplit(command, '|');
	len = -1;
	while (temp_pipes[++len])
		len++;
	exec_pipe(temp_pipes, len, env, val);
	free_2d_array((void**)temp_pipes);
	return (1);
}

int				piping(char *command, char **env, int *val, int *r)
{
	char		*to_send;

	to_send = comma_strip(command);
	pipe_parse(to_send, env, val);
	free(to_send);
	*r = 1;
	return (0);
}
