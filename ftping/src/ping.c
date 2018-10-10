/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:02:10 by angonyam          #+#    #+#             */
/*   Updated: 2018/10/09 11:02:11 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ftping.h"
#include <errno.h>

/*
** leaving space in program args for -c flag handling
*/

void		timelapse(struct timeval timestamp)
{
	struct timeval	current_time;

	gettimeofday(&current_time, 0);
	printf("time=%.2f ms\n", (float)((current_time.tv_usec -
				timestamp.tv_usec)) / 1000);
	g_stats.total_time += current_time.tv_usec - timestamp.tv_usec;
}

void		ping_me(char *addr_info, struct sockaddr_in to,
		int ping_sockfd)
{
	struct sockaddr_in	from;
	t_icmp				echo_packet;
	int					packet_number;
	char				s[1024];
	int					rcv;

	signal(SIGINT, signalhandler);
	ft_memset(&from, 0, sizeof(struct sockaddr_in));
	packet_number = 1;
	while (g_stats.loop)
	{
		ft_memset(&echo_packet, 0, sizeof(t_icmp));
		pack_msg(&echo_packet, packet_number);
		if (sendto(ping_sockfd, &echo_packet, sizeof(t_icmp),
			0, (struct sockaddr *)&to, sizeof(to)) == -1)
			error_and_exit("Error : sendto()");
		receive_message(ping_sockfd, &rcv, s);
		unpack_msg(s, rcv, addr_info);
		timelapse(echo_packet.timestamp);
		packet_number++;
		sleeper(1);
	}
}
