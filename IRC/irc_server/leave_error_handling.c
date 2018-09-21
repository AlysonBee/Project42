/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave_error_handling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 10:53:41 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 10:54:15 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			leave_error_handling(t_user *curr_user)
{
	char	**args;

	if (count_args(curr_user->buffer) > 1)
	{
		ft_bzero(curr_user->buffer, 4096);
		ft_strcpy(curr_user->buffer, "Error : Too many arguments\n");
		send(curr_user->fd, curr_user->buffer, 512, 0);
		ft_bzero(curr_user->buffer, 4096);
		return (0);
	}
	args = split(curr_user->buffer, ' ');
	if (ft_strcmp(args[0], "/leave") != 0)
	{
		ft_bzero(curr_user->buffer, 4096);
		ft_strcpy(curr_user->buffer, "Error : did you mean /leave?\n");
		send(curr_user->fd, curr_user->buffer, 512, 0);
		ft_bzero(curr_user->buffer, 4096);
		return (0);
	}
	free2d(args);
	return (1);
}
