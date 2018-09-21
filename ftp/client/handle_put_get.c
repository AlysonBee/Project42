/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_put_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:18:28 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/02 07:56:38 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ftp.h"

void			handle_put(char *line, char *filename, int sockfd)
{
	unsigned char	*to_send;
	size_t			message_len;
	unsigned char	*file;

	message_len = 0;
	if (scan_for_file(filename) == 1)
	{
		to_send = message_protocol(line);
		message_len += edit_len(to_send) + ft_strlen(line);
		send(sockfd, to_send, message_len, 0);
		file = send_file(filename);
		file_segmentation(file, sockfd);
		ft_putendl("Upload complete");
	}
	else
		ft_putendl("unable to upload file");
}

void			download_file(char *filename, int sockfd)
{
	char			*file;
	char			**pathway;

	printf("file is %s\n", filename);
	if (ft_strchr(filename, '/'))
	{
		pathway = ft_strsplit(filename, '/');
		file = ft_strdup(pathway[arraylen(pathway) - 1]);
		free_2d_array((void**)pathway);
	}
	else
	{
		file = ft_strdup(filename);
	}
	file_seg_recv(sockfd, file);
	ft_putendl("Download complete\n");
	free(file);
}

void			handle_get(char *line, char *filename, int sockfd)
{
	char			sign[6];
	unsigned char	*to_send;
	size_t			message_len;

	to_send = message_protocol(line);
	message_len = edit_len(to_send) + ft_strlen(line);
	send(sockfd, to_send, message_len, 0);
	recv(sockfd, sign, 5, 0);
	if (ft_strcmp(sign, "READY") == 0)
	{
		download_file(filename, sockfd);
		printf("file recieved\n");
	}
	else
		printf("File doesn't exist\n");
}

void			get_or_put(char *buffer, int sockfd)
{
	char			**comm;

	comm = ft_strsplit(buffer, ' ');
	if (ft_strstr(comm[0], "put"))
		handle_put(buffer, comm[1], sockfd);
	else if (ft_strcmp(comm[0], "get") == 0)
		handle_get(buffer, comm[1], sockfd);
	free_2d_array((void**)comm);
}
