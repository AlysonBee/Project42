/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:35:22 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 12:04:18 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "client.h"

t_serv_list		*rollback_connection(t_serv_list *target)
{
	printf("Error connecting : something happened\n");
	free(target->remote_ip);
	free(target);
	target = NULL;
	return (NULL);
}

t_serv_list		*new_extra_conn(
		int port_num, char *address, t_sockaddr_in new_address)
{
	t_serv_list	*new;

	new = (t_serv_list *)malloc(sizeof(t_serv_list));
	new->remote_socket = socket(AF_INET, SOCK_STREAM, 0);
	new->remote_port = port_num;
	new->remote_ip = ft_strdup(address);
	new->remote_address = new_address;
	new->next = NULL;
	if (connect(new->remote_socket, (t_sockaddr *)&new_address,
					sizeof(new_address)) < 0)
		return (rollback_connection(new));
	new->remote_name = name_connection();
	printf("Connected to : %s : %d \n", address, port_num);
	return (new);
}

t_serv_list		*add_extra_conn(t_serv_list *head,
		int port_num, char *address, t_sockaddr_in new_address)
{
	t_serv_list	*trav;

	trav = head;
	while (trav->next)
		trav = trav->next;
	trav->next = (t_serv_list *)malloc(sizeof(t_serv_list));
	trav->next->remote_socket = socket(AF_INET, SOCK_STREAM, 0);
	trav->next->remote_port = port_num;
	trav->next->remote_ip = ft_strdup(address);
	trav->next->remote_address = new_address;
	trav->next->next = NULL;
	if (connect(trav->next->remote_socket,
			(t_sockaddr *)&new_address, sizeof(new_address)) < 0)
		return (rollback_connection(trav->next));
	trav->next->remote_name = name_connection();
	printf("Added : %s : %d to connect list : \n", address, port_num);
	return (trav);
}

t_serv_list		*remote_connect(t_serv_list *head,
		int port_num, char *address, t_sockaddr_in new_address)
{
	t_serv_list	*trav;

	trav = head;
	if (trav == NULL)
	{
		trav = new_extra_conn(port_num, address, new_address);
		head = trav;
	}
	else
	{
		trav = add_extra_conn(head, port_num, address,
				new_address);
		trav = head;
	}
	return (head);
}
