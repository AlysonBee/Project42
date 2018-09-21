/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:17:34 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/31 15:56:50 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftp.h"

void				port_error(void)
{
	printf("port cannot be a negative number\n");
	usage(1);
}

void				usage(int val)
{
	if (val == CLIENT)
		printf("Usage: ./ft_client [server] [port]\n");
	else if (val == SERVER)
		printf("Usage: ./ft_server [port]\n");
	exit(1);
}

void				error(char *from_where)
{
	printf("Error : %s\n", from_where);
	exit(1);
}

t_sockaddr_in		setup_server_addr(char *address)
{
	t_sockaddr_in		server_addr;

	ft_memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(ft_atoi(address));
	return (server_addr);
}

t_sockaddr_in		setup_client_addr(char *address,
		int port)
{
	t_sockaddr_in		client_addr;

	if (port < 0)
		port_error();
	ft_memset(&client_addr, 0, sizeof(client_addr));
	client_addr.sin_family = AF_INET;
	client_addr.sin_addr.s_addr = inet_addr(address);
	client_addr.sin_port = htons(port);
	return (client_addr);
}
