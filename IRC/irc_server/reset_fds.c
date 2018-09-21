/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:02:45 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 11:03:16 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			reset_user_fds(t_serv *server)
{
	t_user		*user;
	t_chan		*channel;

	channel = (*server).channels;
	while (channel)
	{
		user = channel->users;
		while (user)
		{
			FD_SET(user->fd, &(server->readfds));
			if (ft_strlen(user->buffer) > 0)
				FD_SET(user->fd, &(server->writefds));
			if (server->maxfd < user->fd)
				server->maxfd = user->fd;
			user = user->next;
		}
		channel = channel->next;
	}
	if (server->master_sock > server->maxfd)
		server->maxfd = server->master_sock;
	user = (*server).channels->users;
}

void			reset_fds(t_serv *server)
{
	t_chan		*head;

	head = (*server).channels;
	if ((*server).channels == NULL)
		return ;
	while ((*server).channels)
	{
		if ((*server).channels->users == NULL)
			;
		else
			reset_user_fds(server);
		(*server).channels = (*server).channels->next;
	}
	(*server).channels = head;
}
