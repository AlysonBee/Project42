/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:02:28 by angonyam          #+#    #+#             */
/*   Updated: 2018/10/09 11:02:31 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftping.h"
#include <errno.h>

char		*receive_message(int ping_sockfd, int *rcv, char s[])
{
	char				buffer[1024];
	ssize_t				size;
	struct iovec		iov[1];
	struct msghdr		message;
	struct sockaddr_in	from;

	iov[0].iov_base = buffer;
	iov[0].iov_len = sizeof(buffer);
	memset(&from, 0, sizeof(struct sockaddr_in));
	message.msg_name = &from;
	message.msg_namelen = sizeof(from);
	message.msg_iov = iov;
	message.msg_iovlen = 1;
	message.msg_control = 0;
	message.msg_controllen = 0;
	if ((size = recvmsg(ping_sockfd, &message, 0)) == -1)
		error_and_exit("recvmsg()");
	g_stats.rec++;
	*rcv = size;
	memcpy(s, buffer, size);
	return (NULL);
}
