/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 10:42:42 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 13:21:48 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_user	*turn_off_user(t_chan *head, t_user *curr_user, int *flag)
{
	t_user	*userlist;

	userlist = head->users;
	while (userlist)
	{
		if (ft_strcmp(curr_user->username, userlist->username) == 0 ||
			curr_user->fd == userlist->fd)
		{
			*flag = 1;
			curr_user->current_channel = 0;
			break ;
		}
		userlist = userlist->next;
	}
	return (userlist);
}

t_chan	*turn_off_all_other_channels(t_chan *channel, t_user *curr_user)
{
	t_chan	*trav;
	int		flag;

	flag = 0;
	trav = channel;
	while (trav)
	{
		channel->users = turn_off_user(channel, curr_user, &flag);
		if (flag == 1)
			break ;
		trav = trav->next;
	}
	return (channel);
}

t_user	*tell_everyone(t_user *userlist, char *name, t_user *curr_user)
{
	t_user		*trav;

	trav = userlist;
	while (trav)
	{
		if (trav->fd == curr_user->fd)
			;
		else
		{
			ft_bzero(trav->buffer, 4096);
			ft_strcpy(trav->buffer, "Notice : ");
			ft_strcat(trav->buffer, curr_user->username);
			ft_strcat(trav->buffer, " Created the channel : ");
			ft_strcat(trav->buffer, name);
			ft_strcat(trav->buffer, "\n\0");
		}
		trav = trav->next;
	}
	return (userlist);
}

t_chan	*create_command(t_chan *channel, t_user *curr_user,
		t_chan *curr_chan)
{
	char		**args;
	char		*name;
	t_chan		*trav;

	args = split(curr_user->buffer, ' ');
	if (args[1][0] != '#')
		name = join("#", args[1]);
	else
		name = ft_strdup(args[1]);
	channel = turn_off_all_other_channels(channel, curr_user);
	channel = add_channel(channel, name);
	printf("here\n");
	trav = channel;
	while (trav->next)
		trav = trav->next;
	trav->users = new_user(curr_user->fd, curr_user->username);
	ft_bzero(curr_user->buffer, 4096);
	ft_strcpy(curr_user->buffer, "Channel : ");
	ft_strcat(curr_user->buffer, name);
	ft_strcat(curr_user->buffer, " Has been created\n");
	tell_everyone(curr_chan->users, name, curr_user);
	free(name);
	free2d(args);
	return (channel);
}
