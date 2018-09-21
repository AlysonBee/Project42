/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_client.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 12:05:08 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/30 08:02:39 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/select.h>
#include <stdio.h>
#include <stdbool.h>
#include "client.h"

void		zero_client_fd(t_client *client)
{
	FD_ZERO(&(client->readfds));
	FD_ZERO(&(client->writefds));
	FD_SET(client->sockfd, &(client->readfds));
	FD_SET(0, &(client->readfds));
}

void		read_socket(t_client *client, t_circ *circle)
{
	char	buffer[4096];
	size_t	val;

	val = recv(client->sockfd, buffer, 512, 0);
	buffer[val] = '\0';
	write(1, "\n", 1);
	write_circle(circle, buffer);
	if (ft_strstr(buffer, "Nickname successfully changed"))
		user_prompt(client, buffer);
	print_circular(circle);
	write(1, client->prompt, ft_strlen(client->prompt));
}

void		write_socket(t_client *client)
{
	size_t	size;

	read_buffer(client->buffer, 512);
	size = ft_strlen(client->buffer);
	client->buffer[size] = '\0';
	if (ft_strstr(client->buffer, "/connect"))
	{
		if (connect_error(client->buffer) == 1)
			manage_server_cluster(client);
	}
	else if (ft_strstr(client->buffer, "/list"))
		list(client->servers, client);
	else if (ft_strstr(client->buffer, "/switch"))
		switch_command(client);
	else if (coming_soon(client->buffer) == 1)
		;
	else
		send(client->sockfd, client->buffer, 512, 0);
	write(1, client->prompt, strlen(client->prompt));
	if (ft_strstr(client->buffer, "/help"))
		help();
	if (ft_strstr(client->buffer, "/disconnect"))
		disconnection(client->sockfd);
	ft_bzero(client->buffer, 4096);
}

t_serv_list	*first_server_conn(t_client client)
{
	t_serv_list		*serv;

	serv = (t_serv_list *)malloc(sizeof(t_serv_list));
	serv->remote_socket = client.sockfd;
	serv->remote_address = client.client_addr;
	serv->remote_port = client.port;
	serv->remote_ip = ft_strdup(client.ip);
	serv->remote_name = ft_strdup("Main");
	serv->next = NULL;
	return (serv);
}

void		run_client(t_client client)
{
	int				slc;
	int				maxfd;
	t_circ			circle;

	g_sockfd = client.sockfd;
	circle = init_circular(512);
	client.servers = first_server_conn(client);
	client.prompt = ft_strdup("Local$>");
	signal(SIGINT, crash_handler);
	maxfd = client.sockfd;
	while (true)
	{
		zero_client_fd(&client);
		maxfd = client.sockfd;
		slc = select(maxfd + 1, &(client.readfds),
				&(client.writefds), NULL, NULL);
		if (slc)
		{
			if (FD_ISSET(0, &(client.readfds)))
				write_socket(&client);
			else if (FD_ISSET(client.sockfd, &(client.readfds)))
				read_socket(&client, &circle);
		}
		FD_CLR(0, &(client.readfds));
	}
}
