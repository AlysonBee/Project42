/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_channel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:15:15 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 11:15:21 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_chan			*create_channel(char *name)
{
	t_chan		*channel;

	channel = (t_chan *)malloc(sizeof(t_chan));
	channel->channel_name = ft_strdup(name);
	channel->users = NULL;
	channel->next = NULL;
	return (channel);
}

t_chan			*add_channel(t_chan *head, char *name)
{
	t_chan		*trav;

	trav = head;
	while (trav->next)
		trav = trav->next;
	trav->next = (t_chan *)malloc(sizeof(t_chan));
	trav->next->channel_name = ft_strdup(name);
	trav->next->users = NULL;
	trav->next->next = NULL;
	return (trav);
}

t_chan			*channels(t_chan *head, char *name)
{
	t_chan		*trav;

	trav = head;
	if (trav == NULL)
	{
		trav = create_channel(name);
		head = trav;
	}
	else
	{
		trav = add_channel(head, name);
		trav = head;
	}
	return (head);
}
