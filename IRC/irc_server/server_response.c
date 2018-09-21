/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_response.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:01:32 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 13:17:52 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_chan		*join_or_create(t_chan *channel, t_user *userlist)
{
	if (ft_strstr(userlist->buffer, "/join"))
		channel = join_command(channel, userlist);
	else if (ft_strstr(userlist->buffer, "/create"))
		channel = create_command(channel, userlist, channel);
	return (channel);
}

int			check_channel_string(t_user *curr_user)
{
	if (ft_strstr(curr_user->buffer, "/join") ||
		ft_strstr(curr_user->buffer, "/create"))
		return (1);
	return (-1);
}

t_chan		*run_commands(t_chan *channel)
{
	t_user	*userlist;

	userlist = channel->users;
	while (userlist)
	{
		if (ft_strstr(userlist->buffer, "/leave") ||
			ft_strstr(userlist->buffer, "/disconnect"))
		{
			channel = leave_channel(channel, userlist);
			break ;
		}
		else if (ft_strstr(userlist->buffer, "/nick"))
		{
			channel = nick_command(channel, userlist);
			break ;
		}
		else if (check_channel_string(userlist) == 1)
		{
			channel = join_or_create(channel, userlist);
			break ;
		}
		userlist = userlist->next;
	}
	return (channel);
}

void		server_response(t_serv *server)
{
	int		i;
	t_chan	*chanlist;

	chanlist = server->channels;
	i = 0;
	userlist_depth(chanlist->users);
	while (chanlist)
	{
		chanlist = run_commands(chanlist);
		chanlist = chanlist->next;
		i++;
	}
	server->server_comms = 0;
}
