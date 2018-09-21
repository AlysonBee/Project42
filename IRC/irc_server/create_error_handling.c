/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_error_handling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 10:43:47 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 10:44:02 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		create_error_handling(t_user *curr_user)
{
	if (count_args(curr_user->buffer) != 1)
	{
		ft_bzero(curr_user->buffer, 4096);
		ft_strcpy(curr_user->buffer, "Error : Invalid argument count\n");
		send(curr_user->fd, curr_user->buffer, 512, 0);
		ft_bzero(curr_user->buffer, 4096);
		return (0);
	}
	return (1);
}
