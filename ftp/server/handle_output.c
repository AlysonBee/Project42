/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:20:05 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/31 07:20:06 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "server.h"
#include <sys/stat.h>

void		send_error(void)
{
	int		fd;

	fd = open(".output.txt", O_RDWR | O_CREAT | O_TRUNC);
	dup2(fd, 1);
	printf("ls : no such file or directory\n");
	close(fd);
}

char		*create_buffer(char buffer[], char *str)
{
	char	*ret;

	ret = ft_strjoin(str, buffer);
	free(str);
	str = ft_strdup(ret);
	free(ret);
	return (str);
}

void		send_terminal_output(int sockfd)
{
	unsigned char	*val;

	val = send_file(".output.txt");
	file_segmentation(val, sockfd);
}

void		handle_pwd(void)
{
	char	buffer[4096];
	int		fd;

	fd = open(".output.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
	dup2(fd, 1);
	getcwd(buffer, 4096);
	ft_putendl(buffer);
	close(fd);
}

void		handle_ls(char *line)
{
	char	**args;
	int		fd;
	pid_t	pid;
	char	*new;
	int		status;

	status = 0;
	fd = -1;
	new = ft_strjoin(line, " ");
	if ((pid = fork()) == 0)
	{
		fd = open(".output.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
		dup2(fd, 1);
		args = ft_strsplit(new, ' ');
		status = execv("/bin/ls", args);
		free_2d_array((void**)args);
		close(fd);
		exit(1);
	}
	free(new);
	wait(&pid);
	if (WEXITSTATUS(pid) != 0)
		send_error();
	return ;
}
