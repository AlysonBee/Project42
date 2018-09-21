/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_error_handling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 10:42:08 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 10:42:38 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		error_message(t_user *curr_user, char *message)
{
	ft_bzero(curr_user->buffer, 4096);
	ft_strcpy(curr_user->buffer, message);
	send(curr_user->fd, curr_user->buffer, 512, 0);
	ft_bzero(curr_user->buffer, 4096);
}

int			nick_error_handling(t_user *curr_user)
{
	char	**args;

	args = split(curr_user->buffer, ' ');
	if (args == NULL)
	{
		error_message(curr_user, "Error : /nick : usage /nick [new_name]\n");
		return (0);
	}
	if (ft_strcmp(args[0], "/nick") != 0)
	{
		error_message(curr_user, "Error : did you mean /nick?\n");
		return (0);
	}
	if (count_args(curr_user->buffer) != 1)
	{
		error_message(curr_user, "Error : /nick : Too many arguments\n");
		return (0);
	}
	return (1);
}
