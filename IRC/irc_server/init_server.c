/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:05:16 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/30 07:40:18 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			error(char *function)
{
	printf("Error : %s\n", function);
	exit(1);
}

t_sockaddr_in	server_address(int port)
{
	t_sockaddr_in	addr;

	ft_memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	return (addr);
}

void			init_server(t_serv *server, int port)
{
	size_t			val;

	val = 1;
	server->version = 1;
	if ((server->master_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		error("socket");
	server->server_addr = server_address(port);
	setsockopt(server->master_sock, SOL_SOCKET, SO_REUSEADDR,
			(char*)&val, sizeof(val));
	if (bind(server->master_sock, (t_sockaddr *)&server->server_addr,
				sizeof(server->server_addr)) < 0)
		error("bind");
	if (listen(server->master_sock, 5) < 0)
		error("listen");
	server->channels = NULL;
	server->server_comms = 0;
}

int				main(int argc, char **arv)
{
	t_serv			server;

	if (argc != 2)
	{
		printf("Usage : %s [port]\n", arv[0]);
		return (1);
	}
	init_server(&server, atoi(arv[1]));
	signal(11, sign_catch);
	run_server(server);
	return (0);
}
