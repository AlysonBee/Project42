/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disconnect_error_handling.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 10:45:31 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 10:45:47 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			disconnect_error_handling(t_user *curr_user)
{
	if (ft_strcmp(curr_user->buffer, "/disconnect") != 0)
	{
		ft_bzero(curr_user->buffer, 4096);
		ft_strcpy(curr_user->buffer,
				"Error : /disconnect : Usage : /disconnect\n");
		send(curr_user->fd, curr_user->buffer, 512, 0);
		ft_bzero(curr_user->buffer, 4096);
		return (0);
	}
	return (1);
}
