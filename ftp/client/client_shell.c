/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:18:14 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/31 07:18:16 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		send_output(char *line, int sockfd)
{
	unsigned char		*to_send;
	size_t				message_len;

	message_len = 0;
	to_send = message_protocol(line);
	message_len = edit_len(to_send) + ft_strlen(line);
	send(sockfd, to_send, message_len, 0);
	file_seg_recv(sockfd, ".output.txt");
	recieve_terminal_output();
}

void		error_message(int sockfd)
{
	char	buffer[10];

	recv(sockfd, buffer, 7, 0);
	if (ft_strstr(buffer, "FAILED"))
		ft_putstr("cd - Unable to access file\n");
	ft_bzero(buffer, 10);
}

void		change_remote_directory(char *line, int sockfd)
{
	unsigned char		*to_send;
	size_t				message_len;

	message_len = 0;
	to_send = message_protocol(line);
	message_len = edit_len(to_send) + ft_strlen(line);
	send(sockfd, to_send, message_len, 0);
}

void		client_shell(int sockfd)
{
	char	buffer[4096];

	read(0, buffer, 4096);
	terminate_str(buffer);
	if (buffer[0] == '\0')
		;
	else if (check_command_string(buffer, "cd") == 1)
	{
		change_remote_directory(buffer, sockfd);
		error_message(sockfd);
	}
	else if (check_command_string(buffer, "ls") == 1 ||
			check_command_string(buffer, "pwd") == 1)
		send_output(buffer, sockfd);
	else if (ft_strstr(buffer, "get") || ft_strstr(buffer, "put"))
		get_or_put(buffer, sockfd);
	else if (ft_strstr(buffer, "quit"))
	{
		change_remote_directory(buffer, sockfd);
		exit(1);
	}
	else if (buffer[0] != '\0')
		printf("invalid command\n");
	ft_bzero(buffer, 4096);
}
