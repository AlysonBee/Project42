/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_server_cluster.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 12:05:04 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/27 09:36:54 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include "client.h"

void		nulling(char name[])
{
	int		i;

	i = 0;
	while (name[i])
	{
		if (name[i] == '\n')
		{
			name[i] = '\0';
			return ;
		}
		i++;
	}
}

char		*name_connection(void)
{
	char	conn_name[4097];
	char	*name;

	printf("Name the connection\n");
	while (true)
	{
		write(1, "$>", 2);
		read_buffer(conn_name, 4096);
		if (conn_name[0] == '\n' || count_args(conn_name) > 0)
			printf("Invalid name\n");
		else
			break ;
	}
	nulling(conn_name);
	name = ft_strdup(conn_name);
	return (name);
}

t_serv_list	*add_new_server(t_serv_list *servers, int port_num, char *address)
{
	t_sockaddr_in		address2;

	memset(&address2, 0, sizeof(address));
	address2.sin_family = AF_INET;
	address2.sin_addr.s_addr = inet_addr(address);
	address2.sin_port = htons(port_num);
	servers = remote_connect(servers, port_num, address, address2);
	return (servers);
}

void		free_cluster(char **args, char *address)
{
	free2d(args);
	free(address);
}

void		manage_server_cluster(t_client *client)
{
	char		**args;
	t_serv_list	*trav;
	int			port;
	char		*address;
	int			flag;

	flag = 0;
	args = split(client->buffer, ' ');
	port = atoi(args[2]);
	address = ft_strdup(args[1]);
	trav = client->servers;
	while (trav)
	{
		if (ft_strcmp(trav->remote_ip, address) == 0 &&
				port == trav->remote_port)
		{
			flag = 1;
			printf("Notice : You're already connected to this server\n");
			break ;
		}
		trav = trav->next;
	}
	if (flag == 0)
		client->servers = add_new_server(client->servers, port, address);
	free_cluster(args, address);
}
