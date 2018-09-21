/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 10:45:54 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 11:06:04 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*help(void)
{
	char	*output;
	char	buffer[4096];

	ft_bzero(buffer, 4096);
	ft_strcpy(buffer, "Available Commands : ============\n\n");
	ft_strcat(buffer, "General Purpose (for netcat/telnet etc..) :\n");
	ft_strcat(buffer,
			"\t/help  - list available commands \n\t\tUsage : /help\n");
	ft_strcat(buffer, "\t/who   - list all users in current channel\n\t\t");
	ft_strcat(buffer, "Usage : /who\n\t/msg  - message direct user\n\t\t");
	ft_strcat(buffer, "Usage: /msg [username] [message]\n");
	ft_strcat(buffer, "\t/join  - join target channel (channel must exist\n");
	ft_strcat(buffer, "\t/leave - leave current channel/server\n");
	ft_strcat(buffer, "\t\tUsage : /leave OR /leave <channel_name>\n");
	ft_strcat(buffer, "\t/create - create a new channel\n");
	ft_strcat(buffer, "\t\tUsage : /create [channel name]\n");
	ft_strcat(buffer, "====================================\n\n");
	output = ft_strdup(buffer);
	return (output);
}
