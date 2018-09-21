/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_username_gen.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 10:45:27 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 15:02:02 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*default_username_gen(t_user *userlist)
{
	t_user	*trav;
	int		client_num;
	char	*number;
	char	*newname;

	client_num = 1;
	trav = userlist;
	while (trav)
	{
		if (trav->username == NULL)
			break ;
		if (ft_strstr(trav->username, "Client"))
			client_num++;
		trav = trav->next;
	}
	number = itoa(client_num);
	newname = join("Client", number);
	free(number);
	return (newname);
}
