/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:02:04 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/30 06:57:34 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "header.h"

t_user			*free_user_info(t_user *all_users,
		t_user *curr, char *channel_name)
{
	all_users = user_left(all_users, curr, channel_name);
	free(curr->username);
	free(curr->buffer);
	free(curr);
	return (all_users);
}

t_user			*first_or_later(t_user *userlist,
		t_user *curr_user, char *channel_name, t_user *trav)
{
	if (ft_strcmp(trav->username, curr_user->username) == 0 &&
			curr_user->fd == trav->fd)
	{
		userlist = free_user_info(userlist, curr_user, channel_name);
		userlist = trav->next;
		return (userlist);
	}
	while (trav)
	{
		if (ft_strcmp(curr_user->username, trav->next->username)
				== 0 && curr_user->fd == trav->next->fd)
		{
			trav->next = trav->next->next;
			userlist = free_user_info(userlist, curr_user, channel_name);
		}
		trav = trav->next;
	}
	return (userlist);
}

t_user			*remove_user(t_user *userlist, t_user *curr_user,
		char *channel_name)
{
	t_user		*trav;

	trav = userlist;
	if (trav->next == NULL)
	{
		if (ft_strcmp(curr_user->username, trav->username) == 0 &&
				curr_user->fd == trav->fd)
		{
			userlist = free_user_info(userlist, curr_user, channel_name);
			userlist = NULL;
		}
	}
	else
		userlist = first_or_later(userlist, curr_user, channel_name, trav);
	return (userlist);
}

void			automatic_room_leave(char *channel_name, char buffer[])
{
	strcat(buffer, " ");
	strcat(buffer, channel_name);
	strcat(buffer, "\0");
}

t_chan			*leave_channel(t_chan *channel_list, t_user *curr_user)
{
	t_chan		*channels;
	char		**args;
	int			fd;

	fd = curr_user->fd;
	if (count_args(curr_user->buffer) == 0)
		automatic_room_leave("#default", curr_user->buffer);
	args = split(curr_user->buffer, ' ');
	channels = channel_list;
	while (channels)
	{
		if (ft_strcmp(args[1], channels->channel_name) == 0)
		{
			channels->users = remove_user(channels->users,
					curr_user, channels->channel_name);
			curr_user->current_channel = 0;
			break ;
		}
		channels = channels->next;
	}
	if (ft_strcmp(args[0], "/disconnect") == 0)
		closing(fd);
	free2d(args);
	return (channel_list);
}
