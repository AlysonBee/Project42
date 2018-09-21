/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:20:43 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/31 07:20:46 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "server.h"

char		*get_filename(char *path)
{
	char			**file;
	char			*ret;
	int				i;

	i = 0;
	file = NULL;
	if (ft_strchr(path, '/'))
	{
		file = ft_strsplit(path, '/');
		i = arraylen(file) - 1;
		ret = ft_strdup(file[i]);
		free_2d_array((void **)file);
		return (ret);
	}
	return (path);
}

void		handle_get(char *line, int sockfd)
{
	char			**args;
	unsigned char	*file;

	file = NULL;
	args = ft_strsplit(line, ' ');
	if (scan_server_file(args[1]) == 1)
	{
		send(sockfd, "READY", 5, 0);
		file = send_file(args[1]);
		file_segmentation(file, sockfd);
	}
	else
		send(sockfd, "ERROR", 5, 0);
	free_2d_array((void**)args);
}

void		handle_put(char *line, int sockfd)
{
	char			**args;
	char			*filename;

	args = ft_strsplit(line, ' ');
	filename = get_filename(args[1]);
	file_seg_recv(sockfd, filename);
	ft_putstr("received\n");
}

void		handle_output(char *val, int sockfd)
{
	unsigned char	*filestream;
	int				fd;
	struct stat		info;

	if (ft_strstr(val, "pwd"))
		handle_pwd();
	else
		handle_ls(val);
	fd = open(".output.txt", O_RDWR);
	fstat(fd, &info);
	if (info.st_size == 0)
		write(fd, "\n", 1);
	close(fd);
	filestream = send_file(".output.txt");
	file_segmentation(filestream, sockfd);
}

void		server_shell(int sockfd, char buffer[])
{
	char			*val;

	val = unpack(buffer);
	if (ft_strstr(val, "put "))
		handle_put(val, sockfd);
	else if (ft_strstr(val, "get "))
		handle_get(val, sockfd);
	else if (ft_strstr(val, "cd"))
		change_directory(val, sockfd);
	else if (ft_strstr(val, "exit"))
		exit(1);
	else if (ft_strstr(val, "ls") || ft_strstr(val, "pwd"))
		handle_output(val, sockfd);
	free(val);
}
