/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_command_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:04:05 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 11:04:07 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			join_error_handling(t_user *curr_user)
{
	char	**args;

	args = NULL;
	if (count_args(curr_user->buffer) != 1)
	{
		ft_bzero(curr_user->buffer, 4096);
		ft_strcpy(curr_user->buffer, "Error : invalid argument count\n");
		send(curr_user->fd, curr_user->buffer, 512, 0);
		ft_bzero(curr_user->buffer, 4096);
		return (1);
	}
	args = split(curr_user->buffer, ' ');
	if (ft_strcmp(args[0], "/join") != 0)
	{
		ft_bzero(curr_user->buffer, 4096);
		ft_strcpy(curr_user->buffer, "Error : did you mean /join?");
		send(curr_user->fd, curr_user->buffer, 512, 0);
		ft_bzero(curr_user->buffer, 4096);
		free2d(args);
		return (1);
	}
	return (1);
}
