/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_request_handling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:21:47 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/02 07:50:19 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include "../ftp.h"

char		*make_path_name(char *filename, char *curr_dir)
{
	char			*ret;
	char			*new;

	new = ft_strjoin(curr_dir, "/");
	ret = ft_strjoin(new, filename);
	free(new);
	return (ret);
}

int			scan_server_file(char *filename)
{
	char			curr_dir[4096];
	char			*file;
	int				fd;
	struct stat		info;

	getcwd(curr_dir, 4096);
	file = make_path_name(filename, curr_dir);
	fd = open(file, O_RDONLY);
	fstat(fd, &info);
	if (S_ISDIR(info.st_mode))
		return (-1);
	if (fd < 0)
		return (-1);
	close(fd);
	return (1);
}

char		*absolute_path_organize(char *path, char *filename)
{
	char			*temp;
	char			*abs;

	temp = ft_strjoin(path, "/");
	abs = ft_strjoin(temp, filename);
	free(temp);
	return (abs);
}

int			scan_for_file(char *filename)
{
	char			path[4096];
	char			*absolute_path;
	int				fd;
	struct stat		info;

	getcwd(path, 4096);
	if (filename[0] != '/')
		absolute_path = absolute_path_organize(path, filename);
	else
		absolute_path = ft_strjoin(path, filename);
	fd = open(absolute_path, O_RDONLY);
	fstat(fd, &info);
	if (info.st_mode == DT_DIR || fd < 0)
	{
		printf("file not found. Perhaps it's a directory?\n");
		close(fd);
		free(absolute_path);
		return (-1);
	}
	close(fd);
	free(absolute_path);
	return (1);
}
