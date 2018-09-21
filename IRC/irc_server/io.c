/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:03:00 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 13:17:34 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		rfc_type_string(char buffer[])
{
	int		i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			return ;
		}
		i++;
	}
}

int			recv_buffer(t_user *curr_user)
{
	size_t	val;
	char	temp[4096];

	val = recv(curr_user->fd, temp, 512, 0);
	temp[val] = '\0';
	if (!ft_strchr(temp, '\n'))
	{
		ft_strcat(curr_user->buffer, temp);
		ft_bzero(temp, 4096);
		return (1);
	}
	ft_strcat(curr_user->buffer, temp);
	ft_strcat(curr_user->buffer, "\0");
	rfc_type_string(curr_user->buffer);
	return (0);
}

t_user		*user_looping_read(t_chan *channel, t_serv *server, int server_n)
{
	t_user	*trv;

	server_n = server->server_comms;
	trv = channel->users;
	while (trv)
	{
		if (FD_ISSET(trv->fd, &(server->readfds)) && trv->current_channel == 1)
		{
			if ((trv->ctrl_d = recv_buffer(trv)) == 1)
			{
				trv = trv->next;
				continue ;
			}
			if (ft_strstr(trv->buffer, "/msg"))
				server = msg_command(server, trv);
			else if ((server_n = is_server_command(trv->buffer,
				server->server_comms, trv)) > server->server_comms)
				server->server_comms = server_n;
			else
				channel->users = write_to_all(channel, trv);
			FD_CLR(trv->fd, &((*server).readfds));
		}
		trv = trv->next;
	}
	return (channel->users);
}

t_user		*user_looping_write(t_user *users, t_serv *server)
{
	t_user	*trav;

	trav = users;
	while (trav)
	{
		if (FD_ISSET(trav->fd, &((*server).writefds)) &&
				trav->current_channel == 1)
		{
			if (trav->ctrl_d == 1)
			{
				trav = trav->next;
				continue ;
			}
			send(trav->fd, trav->buffer, ft_strlen(trav->buffer), 0);
			FD_CLR(trav->fd, &((*server).writefds));
			ft_bzero(trav->buffer, 4096);
		}
		trav = trav->next;
	}
	return (users);
}

t_chan		*server_io(t_serv *server)
{
	t_chan	*channeling;
	int		server_n;

	server_n = 0;
	channeling = server->channels;
	while (channeling)
	{
		channeling->users = user_looping_write(channeling->users, server);
		channeling->users = user_looping_read(channeling, server, server_n);
		channeling = channeling->next;
	}
	return (server->channels);
}
