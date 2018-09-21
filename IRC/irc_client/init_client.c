/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 12:04:34 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 15:17:57 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "client.h"

t_sockaddr_in		cmd_create_address(char *addr, int port)
{
	t_sockaddr_in	saddr;

	memset(&saddr, 0, sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(port);
	saddr.sin_addr.s_addr = inet_addr(addr);
	return (saddr);
}

t_sockaddr_in		create_address(char *buffer, t_client *client)
{
	char			**args;
	int				port;
	t_sockaddr_in	addr;

	args = split(buffer, ' ');
	port = atoi(args[2]);
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(args[1]);
	client->ip = ft_strdup(args[1]);
	client->port = port;
	free2d(args);
	return (addr);
}

int					login_shell(t_client *client)
{
	printf(" Warning : You're not connected to a server\n");
	printf(" Please connect before continuing\n");
	while (1)
	{
		read_buffer(client->buffer, 512);
		if (ft_strlen(client->buffer) <= 1)
			continue ;
		if (sanity_checks(client->buffer) == 1)
		{
			client->client_addr = create_address(client->buffer, client);
			if (connect(client->sockfd, (t_sockaddr *)&(client->client_addr),
				sizeof(client->client_addr)) < 0)
			{
				printf("Error :failed to connect. Please try again\n");
				continue ;
			}
			else
				break ;
		}
	}
	return (1);
}

int					auto_assign_ip(t_client *client, char **argv)
{
	if ((client->ip = ft_strdup(argv[1])) == NULL)
	{
		printf(
		"IP address Error : Something went wrong with the IP you entered\n");
		return (-1);
	}
	if ((client->port = atoi(argv[2])) == 0)
	{
		printf("Port error : Not a valid port\n");
		return (-1);
	}
	client->client_addr = cmd_create_address(client->ip, client->port);
	if (connect(client->sockfd,
		(t_sockaddr *)&(client->client_addr), sizeof(client->client_addr))
			< 0)
	{
		printf(
		"Bad connection error : please check your port numbers\n");
		return (-1);
	}
	return (1);
}

void				init_client(t_client *client, int argc, char **argv)
{
	if ((client->sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		error_and_quit("client");
	if (argc == 3)
	{
		if (auto_assign_ip(client, argv))
			return ;
	}
	else
	{
		if (login_shell(client) == 1)
			printf("Connected : welcome user\n");
	}
}
