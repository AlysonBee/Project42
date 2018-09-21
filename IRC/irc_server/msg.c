/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 10:54:58 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/30 07:07:27 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_user			*user_search(t_user *userlist, char *user, int *i)
{
	t_user		*trav;

	trav = userlist;
	while (trav)
	{
		if (ft_strcmp(trav->username, user) == 0)
		{
			*i = 1;
			break ;
		}
		trav = trav->next;
	}
	return (trav);
}

void			create_message(t_user *curr_info, char trav_buffer[])
{
	char		*str;
	int			i;
	int			count;

	count = 0;
	str = ft_strdup(curr_info->buffer);
	i = 0;
	while (str[i] && count != 2)
	{
		if (my_isspace(str[i]))
		{
			count++;
			while (my_isspace(str[i]))
				i++;
		}
		else
			i++;
	}
	ft_bzero(trav_buffer, 4096);
	ft_strcpy(trav_buffer, "[");
	ft_strcat(trav_buffer, curr_info->username);
	ft_strcat(trav_buffer, "] : ");
	ft_strcat(trav_buffer, &str[i]);
	ft_strcat(trav_buffer, "        [private]\n\0");
}

t_user			*searching_users(t_user *userlist,
		t_user *my_info, int *flag)
{
	char		**command_str;
	t_user		*trav;
	int			me;
	int			them;

	me = 0;
	them = 0;
	trav = userlist;
	command_str = split(my_info->buffer, ' ');
	if (ft_strcmp(command_str[0], "/msg") != 0)
	{
		*flag = 2;
		return (userlist);
	}
	trav = user_search(userlist, my_info->username, &me);
	trav = userlist;
	trav = user_search(userlist, command_str[1], &them);
	if (me == 1 && them == 1)
	{
		create_message(my_info, trav->buffer);
		*flag = 1;
	}
	free2d(command_str);
	return (userlist);
}

t_serv			*msg_command(t_serv *server, t_user *my_info)
{
	t_chan		*head;
	int			flag;

	if (count_args(my_info->buffer) < 2)
	{
		ft_bzero(my_info->buffer, 4096);
		ft_strcpy(my_info->buffer, "msg Error : Invalid argument count\n");
	}
	flag = 0;
	head = server->channels;
	while (head)
	{
		head->users = searching_users(head->users, my_info, &flag);
		if (flag == 1)
			break ;
		head = head->next;
	}
	ft_bzero(my_info->buffer, 4096);
	if (flag == 0)
		ft_strcpy(my_info->buffer,
				"msg error : Unable to find specified user\n");
	else if (flag == 2)
		ft_strcpy(my_info->buffer, "msg error : did you mean /msg? \n");
	return (server);
}
