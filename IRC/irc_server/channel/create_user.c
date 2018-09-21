/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_user.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:15:26 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 11:15:37 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_user		*new_user(int ufd, char *name)
{
	t_user	*new;

	new = (t_user *)malloc(sizeof(t_user));
	new->fd = ufd;
	new->ctrl_d = 0;
	new->current_channel = 1;
	new->username = ft_strdup(name);
	new->buffer = (char*)malloc(sizeof(char) * 4096);
	new->next = NULL;
	return (new);
}

t_user		*add_user(t_user *head, int ufd, char *name)
{
	t_user	*trav;

	trav = head;
	while (trav->next)
		trav = trav->next;
	trav->next = (t_user*)malloc(sizeof(t_user));
	trav->next->fd = ufd;
	trav->next->ctrl_d = 0;
	trav->next->current_channel = 1;
	trav->next->username = ft_strdup(name);
	trav->next->buffer = (char*)malloc(sizeof(char) * 4096);
	trav->next->next = NULL;
	return (trav);
}

t_user		*create_user(t_user *userlist, int ufd, char *name)
{
	t_user	*newuser;

	newuser = userlist;
	if (newuser == NULL)
	{
		newuser = new_user(ufd, name);
		userlist = newuser;
	}
	else
	{
		newuser = add_user(userlist, ufd, name);
		newuser = userlist;
	}
	return (userlist);
}
