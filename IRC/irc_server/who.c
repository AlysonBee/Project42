/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 11:01:24 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 12:36:41 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*who_error(char *command)
{
	char	*output;

	if (ft_strstr(command, "/who"))
		output = ft_strdup("Command Error : Usage : /who\n");
	else
	{
		output = (char*)malloc(sizeof(char) * 4096);
		ft_strcpy(output,
			"Please note that if you aren't using the official client\n");
		ft_strcat(output,
			"a lot of commands (such as /connect) won't work.\n");
		ft_strcat(output, "Please run the official client for those\n");
		ft_strcat(output, "\0");
	}
	return (output);
}

char		*who_command(t_user *user, char *channel_name)
{
	char	*output;
	t_user	*trav;

	output = (char*)malloc(sizeof(char) * 512);
	ft_strcpy(output, "CHANNEL : ");
	ft_strcat(output, channel_name);
	ft_strcat(output, "\n=========================\n\n");
	trav = user;
	while (trav)
	{
		ft_strcat(output, " --> ");
		ft_strcat(output, trav->username);
		ft_strcat(output, "\n");
		trav = trav->next;
	}
	ft_strcat(output, "===========================\n\n");
	ft_strcat(output, "\0");
	return (output);
}
