/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_transfer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:22:07 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/31 07:22:08 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../ftp.h"

int					map_file_content(unsigned char **content,
		size_t *size, char *filename)
{
	int			fd;
	struct stat	info;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Unable to open file\n");
		exit(1);
	}
	fstat(fd, &info);
	*size = info.st_size;
	*content = mmap(0, *size, PROT_READ,
			MAP_PRIVATE, fd, 0);
	if (*content == MAP_FAILED)
	{
		printf("Unable to send file : FAILED");
		exit(1);
		return (-1);
	}
	return (1);
}

int					map_buffer(unsigned char **filestream,
		char *message_length, size_t filesize)
{
	size_t			len;

	len = ft_strlen(message_length) + 4 + filesize;
	*filestream = mmap(0, len, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
			-1, 0);
	if (filestream == MAP_FAILED)
	{
		printf("Oh shit guv...\n");
		return (-1);
	}
	return (1);
}

unsigned char		*send_file(char *filename)
{
	unsigned char	*content;
	size_t			file_size;
	unsigned char	*filestream;
	char			*message_length;

	if (map_file_content(&content, &file_size, filename) == -1)
		return (NULL);
	message_length = ft_itoa(file_size);
	map_buffer(&filestream, message_length, file_size);
	filestream = write_file_magic(filestream, message_length, (char*)content,
			file_size);
	return (filestream);
}
