/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_joining.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:16:16 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 11:16:18 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"
#include <unistd.h>

t_user			*join_message(t_user *users)
{
	char		*join;
	t_user		*trav;

	join = ft_strdup("\n>> New User has joined\n\n");
	trav = users;
	while (trav)
	{
		ft_strcpy(trav->buffer, join);
		trav = trav->next;
	}
	free(join);
	return (users);
}

char			*create_default_name(int i)
{
	char		*newstr;

	newstr = ft_strdup("Client");
	newstr = charpush(newstr, (i + '0'));
	return (newstr);
}

char			*determine_client_name(char **users)
{
	int			i;

	i = 0;
	if (users == NULL)
		return (create_default_name(i));
	while (users[i])
	{
		if (ft_strstr(users[i], "Client"))
			break ;
		i++;
	}
	return (create_default_name(i));
}

t_chan			*joining_user(t_chan *channel, t_serv *server)
{
	int				acceptsock;
	socklen_t		valu;
	t_serv			copy;

	copy = *server;
	valu = sizeof(copy.server_addr);
	acceptsock = accept(copy.master_sock, (t_sockaddr *)&copy.server_addr,
			(socklen_t *)&valu);
	if (channel == NULL)
		channel = channels(channel, "#default");
	channel->users = create_user(channel->users, acceptsock,
				default_username_gen(channel->users));
	channel->users = join_message(channel->users);
	FD_SET(acceptsock, &(server->readfds));
	return (channel);
}
