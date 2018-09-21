/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 10:54:19 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 10:54:44 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*leave_message(t_user *info, char *channel_name)
{
	char	*message;

	ft_bzero(info->buffer, 4096);
	ft_strcpy(info->buffer, "User :");
	ft_strcat(info->buffer, info->username);
	ft_strcat(info->buffer, " Has left : ");
	ft_strcat(info->buffer, channel_name);
	ft_strcat(info->buffer, "\n");
	message = ft_strdup(info->buffer);
	return (message);
}

t_user		*user_left(t_user *all_users, t_user *leaving_user,
		char *channel_name)
{
	char	*exit_message;
	t_user	*trav;

	exit_message = leave_message(leaving_user, channel_name);
	trav = all_users;
	while (trav)
	{
		ft_bzero(trav->buffer, 4096);
		ft_strcpy(trav->buffer, exit_message);
		trav = trav->next;
	}
	return (all_users);
}
