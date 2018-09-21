/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broadcasting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 10:36:03 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 12:36:57 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*who_or_help(char *comm, char *channel_name, t_user *users)
{
	char	*output;

	if (ft_strstr(comm, "/help"))
		output = help();
	else
		output = who_command(users, channel_name);
	return (output);
}

t_user		*who(t_user *users, int current_user, char *comm,
		char *channel_name)
{
	char	*output;
	t_user	*trav;

	trav = users;
	if (command_sanity_check(comm) == 1)
		output = who_or_help(comm, channel_name, users);
	else
		output = who_error(comm);
	while (trav)
	{
		if (trav->fd == current_user)
		{
			ft_bzero(trav->buffer, 4096);
			ft_strcpy(trav->buffer, output);
			send(trav->fd, trav->buffer, 512, 0);
			free(output);
			ft_bzero(trav->buffer, 4096);
			break ;
		}
		trav = trav->next;
	}
	bzero(comm, 4096);
	return (users);
}

t_user		*write_to_all(t_chan *channel, t_user *curr_user)
{
	t_user	*trav;

	trav = channel->users;
	if (curr_user->buffer[0] == '/')
		return (who(channel->users, curr_user->fd,
			curr_user->buffer, channel->channel_name));
	else
		while (trav)
		{
			if (trav->fd == curr_user->fd)
				;
			else
			{
				create_prompt(curr_user, channel->channel_name);
				ft_strcat(trav->buffer, curr_user->buffer);
				ft_strcat(trav->buffer, "\n");
			}
			trav = trav->next;
		}
	ft_bzero(curr_user->buffer, 4096);
	return (channel->users);
}
