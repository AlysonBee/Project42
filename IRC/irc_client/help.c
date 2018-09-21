/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 12:04:28 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/26 12:04:31 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void		help(void)
{
	printf("\nClient specific commands===========\n");
	printf("\t/list    - list all available servers\n\t\t");
	printf("Usage: /list\n");
	printf("\t/switch   - switch current server\n\t\t");
	printf("Usage : /switch [server_name]\n\t\t");
	printf("Note  : see /list for server list\n");
	printf("\t/connect  - connect to a new server\n\t\t");
	printf("Usage : /connect [server] [port]\n");
	printf("\t/disconnect - disconnect client\n\t\t");
	printf("Usage : /disconnect\n");
	printf("=====================================\n\n");
}
