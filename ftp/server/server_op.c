/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:20:35 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/31 07:20:38 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void			accept_fork(int accept_sock)
{
	char		buffer[4096];
	ssize_t		message_len;

	ft_bzero(buffer, sizeof(buffer));
	while (SERVER)
	{
		message_len = recv(accept_sock, buffer, 4096, 0);
		server_shell(accept_sock, buffer);
		ft_memset(buffer, 0, 4096);
	}
}

void			server_op(int sockfd, t_sockaddr_in address)
{
	int			accept_sock;
	socklen_t	address_len;
	pid_t		pid;

	address_len = sizeof(address);
	while (SERVER)
	{
		accept_sock = accept(sockfd, (t_sockaddr *)&address,
				&address_len);
		if ((pid = fork()) == 0)
		{
			close(sockfd);
			printf("Client connected from address %s\n",
					inet_ntoa(address.sin_addr));
			printf("forking...\n");
			accept_fork(accept_sock);
		}
	}
}
