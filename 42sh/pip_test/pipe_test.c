/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 07:33:28 by angonyam          #+#    #+#             */
/*   Updated: 2017/12/07 09:14:27 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		 main(int argc, char **argv)
{
	pid_t 	pid;
	int		mypipe[2];
	int		ret;
	char	buff[20];

	ret = pipe(mypipe);
	if (ret == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid = fork();
	if (pid == 0)
	{
		write(mypipe[1], "Hello There", 11);
		printf("Child process\n");
	}
	else
	{
		printf("Parent process\n");
		read(mypipe[0], buff, 15);
		printf("buff is %s\n", buff);
	}
	return (0);
}





