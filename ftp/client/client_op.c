/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:18:05 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/31 07:18:06 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int				g_sock;

void			signal_handle(int signal)
{
	unsigned char		*message;
	size_t				message_len;

	printf("signal caught : %d\n", signal);
	message = message_protocol("exit");
	message_len = edit_len(message) + 4;
	send(g_sock, message, message_len, 0);
	exit(1);
}

void			client_op(int sockfd)
{
	g_sock = sockfd;
	while (CLIENT)
	{
		ft_putstr("Client$>");
		signal(SIGINT, signal_handle);
		client_shell(sockfd);
	}
}
