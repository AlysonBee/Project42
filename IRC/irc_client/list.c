/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 12:04:39 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 12:04:55 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		list(t_serv_list *cluster, t_client *client)
{
	t_serv_list	*trav;

	trav = cluster;
	printf("Connected servers =========================\n");
	while (trav)
	{
		printf("IP : %s\t", trav->remote_ip);
		printf("PORT : %d\t", trav->remote_port);
		printf("NAME : %s", trav->remote_name);
		if (client->sockfd == trav->remote_socket)
			printf("\t<- (You are here)");
		printf("\n");
		trav = trav->next;
	}
	printf("=============================================\n\n");
}
