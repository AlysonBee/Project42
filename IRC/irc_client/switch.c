/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 12:05:15 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/27 09:51:02 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int			switch_error_handling(char buffer[])
{
	char	**args;

	if (count_args(buffer) != 1)
	{
		printf("Error : Usage : /switch [target server]\n");
		return (-1);
	}
	args = split(buffer, ' ');
	if (ft_strcmp(args[0], "/switch") != 0)
	{
		printf("Error : did you mean /switch?\n");
		return (-1);
	}
	return (1);
}

void		null_arg(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '\n')
		{
			arg[i] = '\0';
			return ;
		}
		i++;
	}
}

void		switch_command(t_client *client)
{
	char		**args;
	t_serv_list	*trav;
	int			flag;

	flag = 0;
	if (switch_error_handling(client->buffer) == -1)
		return ;
	trav = client->servers;
	args = split(client->buffer, ' ');
	null_arg(args[1]);
	while (trav)
	{
		if (ft_strcmp(trav->remote_name, args[1]) == 0)
		{
			printf("Switching server connection to : %s\n",
					trav->remote_name);
			client->sockfd = trav->remote_socket;
			flag = 1;
			break ;
		}
		trav = trav->next;
	}
	if (flag == 0)
		printf("Server target not found\n");
}
