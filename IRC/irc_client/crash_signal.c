/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crash_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 12:04:22 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/30 09:42:25 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "client.h"

void		disconnection(int sockfd)
{
	send(sockfd, "/disconnect\n\0", 512, 0);
	printf("Disconnected.\n");
	close(sockfd);
	exit(1);
}

void		crash_handler(int num)
{
	printf("signal caught : %d\n", num);
	send(g_sockfd, "/disconnect\n\0", 512, 0);
	printf("Disconnected.\n");
	close(g_sockfd);
	exit(1);
}
