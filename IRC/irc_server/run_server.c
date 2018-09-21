/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_server.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:02:26 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/30 07:40:25 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdbool.h>

void		zero_file_descriptors(t_serv *server)
{
	FD_ZERO(&(server->readfds));
	FD_ZERO(&(server->writefds));
	FD_SET(server->master_sock, &(server->readfds));
}

void		run_server(t_serv server)
{
	int		slc;

	server.maxfd = server.master_sock;
	while (true)
	{
		zero_file_descriptors(&server);
		reset_fds(&server);
		slc = select(server.maxfd + 1, &server.readfds,
				&server.writefds, NULL, NULL);
		if (FD_ISSET(server.master_sock, &(server.readfds)))
			server.channels = joining_user(server.channels, &server);
		else if (server.server_comms > 0)
			server_response(&server);
		else
			server_io(&server);
	}
}
