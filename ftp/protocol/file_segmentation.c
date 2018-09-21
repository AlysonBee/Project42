/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_segmentation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:22:02 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/02 07:38:24 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "../ftp.h"

void			instant_transmission(unsigned char *filestream,
		int sockfd, size_t size)
{
	size_t			num_len;

	size = ft_atoi((const char *)filestream);
	num_len = number_len(size);
	size += num_len + 4;
	send(sockfd, filestream, size, 0);
	return ;
}

void			file_segmentation(unsigned char *filestream,
		int sockfd)
{
	size_t			byte_count;
	size_t			i;
	size_t			numlen;
	size_t			total;
	int				sig;

	byte_count = ft_atoi((const char *)filestream);
	numlen = number_len(byte_count);
	total = byte_count + numlen + 4;
	sig = 1;
	if (total <= 500)
		return (instant_transmission(filestream, sockfd, total));
	i = 0;
	while (i < total)
	{
		send(sockfd, &filestream[i], 500, 0);
		i += 500;
	}
}

void			instant_reception(char buffer[], int fd)
{
	size_t			size;
	size_t			number_l;
	size_t			origin;

	size = ft_atoi(buffer);
	origin = size;
	number_l = number_len(size);
	size += number_l + 4;
	write(fd, &buffer[number_l + 4], origin);
}

unsigned char	*file_recieve_loop(unsigned char *file,
		char buffer[], int sockfd, size_t total)
{
	size_t			i;
	ssize_t			read;

	i = 0;
	ft_memcpy(&file[i], buffer, 500);
	i += 500;
	while (i < total)
	{
		ft_bzero(buffer, 500);
		read = recv(sockfd, buffer, 500, 0);
		ft_memcpy(&file[i], buffer, (size_t)read);
		i += read;
	}
	ft_bzero(buffer, 500);
	return (file);
}

void			file_seg_recv(int sockfd, char *filename)
{
	size_t			total;
	int				fd;
	char			*itoa_string;
	unsigned char	*file;
	char			buffer[4096];

	fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0777);
	recv(sockfd, buffer, 500, 0);
	total = ft_atoi(buffer);
	itoa_string = ft_itoa(total);
	map_buffer(&file, itoa_string, total);
	if (total > 500)
	{
		file = file_recieve_loop(file, buffer, sockfd, total);
		write(fd, &file[ft_strlen(itoa_string) + 4], total);
	}
	else
		instant_reception(buffer, fd);
	free(itoa_string);
	close(fd);
}
