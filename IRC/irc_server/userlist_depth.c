/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userlist_depth.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:02:18 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 11:02:20 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		userlist_depth(t_user *head)
{
	int		i;
	t_user	*trav;

	trav = head;
	i = 0;
	while (trav)
	{
		i++;
		printf("user is %s\n", trav->username);
		trav = trav->next;
	}
	return (i);
}
