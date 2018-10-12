/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 08:11:36 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/07 08:34:26 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int			main(int argc, char **argv, char **envp)
{
	int		pi;
	pid_t	pid;
	int		pipefd[2];
	int		save;
	char	**env;
	char	*str;
	char	**arr;
	int		val;
	char 	buff[10000];
	env = ft_arraydup(envp);
	save = dup(1);
	str = (char*)malloc(sizeof(char) * 1000);
	read(0, str, 1000);
	pi = pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		dup2(pipefd[0], 1);
		arr = ft_strsplit(str, ' ');
		ft_env(env);
	}
	else
	{
		read(pipefd[1], buff, 1000);
		printf("%s", buff);
	}
}
