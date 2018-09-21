/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_comms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:02:33 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 11:02:35 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			is_server_command(char *comm, int server_comm, t_user *curr_user)
{
	if (comm[0] != '/')
		return (server_comm);
	if (ft_strstr(comm, "/nick"))
		return (server_comm + nick_error_handling(curr_user));
	if (ft_strstr(comm, "/join"))
		return (server_comm + join_error_handling(curr_user));
	if (ft_strstr(comm, "/leave"))
		return (server_comm + leave_error_handling(curr_user));
	if (ft_strstr(comm, "/disconnect"))
		return (server_comm + disconnect_error_handling(curr_user));
	if (ft_strstr(comm, "/create"))
		return (server_comm + create_error_handling(curr_user));
	return (server_comm);
}
