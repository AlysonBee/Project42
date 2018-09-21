/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 10:56:44 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 12:39:03 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_user		*edit_username(t_user *current_user, t_user *all_users, int *flag)
{
	t_user	*all;
	char	**args;

	args = split(current_user->buffer, ' ');
	all = all_users;
	while (all)
	{
		if (ft_strcmp(all->username, args[1]) == 0
				&& all->fd != current_user->fd)
		{
			nick_error(current_user->buffer, flag,
					"Error : User already exists\n");
			break ;
		}
		else if (ft_strcmp(all->username, args[1]) == 0 &&
				all->fd == current_user->fd)
		{
			nick_error(current_user->buffer, flag,
					"Notice : That's already your name\n");
			break ;
		}
		all = all->next;
	}
	free2d(args);
	return (all_users);
}

t_user		*username_change_message(t_user *curr_user)
{
	ft_bzero(curr_user->buffer, 4096);
	ft_strcpy(curr_user->buffer, "Nickname successfully changed to : ");
	ft_strcat(curr_user->buffer, curr_user->username);
	ft_strcat(curr_user->buffer, "\n");
	return (curr_user);
}

t_user		*nick_update_broadcast(int fd, t_user *all_usrs,
		char *old, char *new)
{
	t_user	*trav;

	trav = all_usrs;
	while (trav)
	{
		if (trav->fd == fd)
			;
		else
		{
			ft_bzero(trav->buffer, 4096);
			ft_strcpy(trav->buffer, "User : ");
			ft_strcat(trav->buffer, old);
			ft_strcat(trav->buffer, " changed their name to ");
			ft_strcat(trav->buffer, new);
			ft_strcat(trav->buffer, "\n");
		}
		trav = trav->next;
	}
	return (all_usrs);
}

t_user		*change_user_nickname(t_user *curr_user, t_user *userlist)
{
	t_user	*trav;
	char	**args;

	trav = userlist;
	while (trav)
	{
		if (ft_strcmp(trav->username, curr_user->username) == 0 &&
				trav->fd == curr_user->fd)
		{
			args = split(curr_user->buffer, ' ');
			userlist = nick_update_broadcast(trav->fd, userlist,
					trav->username, args[1]);
			free(curr_user->username);
			curr_user->username = ft_strdup(args[1]);
			curr_user = username_change_message(curr_user);
			break ;
		}
		trav = trav->next;
	}
	return (userlist);
}

t_chan		*nick_command(t_chan *channel, t_user *curr_user)
{
	int		flag;
	t_user	*trav;

	flag = 0;
	trav = channel->users;
	edit_username(curr_user, channel->users, &flag);
	if (flag == 0)
		channel->users = change_user_nickname(curr_user, channel->users);
	return (channel);
}
