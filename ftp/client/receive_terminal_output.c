/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_terminal_output.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:18:40 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/02 07:39:11 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "../ftp.h"

void		delete_output(void)
{
	pid_t	pid;
	char	**arg;

	arg = NULL;
	if ((pid = fork() == 0))
	{
		arg = ft_strsplit("rm .output.txt", ' ');
		execv(arg[0], arg);
		free_2d_array((void**)arg);
		exit(1);
	}
	wait(&pid);
}

void		print_ls_content(char **array)
{
	size_t			i;

	i = 0;
	while (array[i])
	{
		if (ft_strstr(array[i], ".output.txt"))
		{
			i++;
			continue ;
		}
		ft_putendl(array[i]);
		i++;
	}
	free_2d_array((void**)array);
}

void		recieve_terminal_output(void)
{
	char			**array;
	char			*buff;
	struct stat		info;
	size_t			i;
	int				fd;

	fd = open(".output.txt", O_RDONLY);
	fstat(fd, &info);
	buff = (char*)malloc(sizeof(char) * info.st_size + 1);
	i = read(fd, buff, info.st_size);
	buff[i] = '\0';
	close(fd);
	array = ft_strsplit(buff, '\n');
	if (array == NULL)
		ft_putendl(buff);
	else
		print_ls_content(array);
	free(buff);
	delete_output();
}
