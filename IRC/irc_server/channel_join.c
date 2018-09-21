/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 10:36:17 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/28 07:54:31 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_user		*check_double_join(t_user *userlist, t_user *curr_user, int *flag)
{
	t_user	*trav;

	trav = userlist;
	while (trav)
	{
		if (ft_strcmp(trav->username, curr_user->username) == 0)
		{
			ft_bzero(curr_user->buffer, 4096);
			ft_strcpy(curr_user->buffer,
					"Error : a matching name was found in this channel\n");
			ft_strcat(curr_user->buffer,
					"consider changing your nickname to resolve\n");
			*flag = -1;
			break ;
		}
		trav = trav->next;
	}
	return (userlist);
}

t_user		*adding_user(t_chan *channel, t_user *curr_user)
{
	t_user	*trav;

	trav = channel->users;
	channel->users = create_user(channel->users, curr_user->fd,
		default_username_gen(channel->users));
	announce_user_arrival(channel->users, curr_user, channel->channel_name);
	return (channel->users);
}

t_user		*announce_user_arrival(t_user *userlist, t_user *curr_user,
		char *channel_name)
{
	t_user	*trav;

	trav = userlist;
	while (trav)
	{
		if (trav->fd == curr_user->fd)
			;
		else
		{
			ft_bzero(trav->buffer, 4096);
			ft_strcpy(trav->buffer, " New user :");
			ft_strcat(trav->buffer, curr_user->username);
			ft_strcat(trav->buffer, " Has joined the channel\n\n");
			ft_strcat(trav->buffer, "\0");
		}
		trav = trav->next;
	}
	ft_bzero(curr_user->buffer, 4096);
	ft_strcpy(curr_user->buffer, "Joined : ");
	ft_strcat(curr_user->buffer, channel_name);
	ft_strcat(curr_user->buffer, "\n\n\0");
	return (userlist);
}

char		*nulling(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '\n')
		{
			arg[i] = '\0';
			break ;
		}
		i++;
	}
	return (arg);
}

t_chan		*join_command(t_chan *channel, t_user *curr_user)
{
	char	**args;
	t_chan	*trav;
	int		flag;

	flag = 0;
	trav = channel;
	args = split(curr_user->buffer, ' ');
	while (trav)
	{
		if (ft_strcmp(trav->channel_name, nulling(args[1])) == 0)
		{
			flag = 1;
			channel->users = check_double_join(trav->users, curr_user, &flag);
			if (flag == 1)
			{
				channel = turn_off_all_other_channels(channel, curr_user);
				trav->users = adding_user(trav, curr_user);
			}
		}
		trav = trav->next;
	}
	if (flag == 0)
		join_error(curr_user->buffer);
	free2d(args);
	return (channel);
}
