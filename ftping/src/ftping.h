/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftping.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:03:07 by angonyam          #+#    #+#             */
/*   Updated: 2018/10/09 11:03:08 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPING_H
# define FTPING_H

# include "lib.h"
# include <arpa/inet.h>
# include <netdb.h>
# include <sys/socket.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <signal.h>
# include <stdbool.h>

# define ICMP_SIZE		(sizeof(struct icmp));
# define ICMP_ECHO		8
# define ICMP_ECHOREPLY	0

# define BREAK_UP		false

typedef struct		s_icmp
{
	unsigned char		type;
	unsigned char		code;
	unsigned short		checksum;
	unsigned short		id;
	unsigned short		sequence;
	struct timeval		timestamp;
}					t_icmp;

typedef struct		s_ip
{
	unsigned char		hlen;
	unsigned char		version;
	unsigned char		tos;
	unsigned short		len;
	unsigned short		id;
	unsigned short		offset;
	unsigned char		ttl;
	unsigned char		protocol;
	unsigned short		checksum;
	struct in_addr		source_ip;
	struct in_addr		dest_ip;
}					t_ip;

typedef struct		s_statistics
{
	char				*flags;
	int					loop;
	char				*hostname;
	int					transm;
	int					rec;
	long long			total_time;
	int					loss_percent;
	int					balance;
	struct timeval		starttime;
}					t_stats;

/*
** global variable to coordinate signal handling
*/

t_stats				g_stats;

/*
** resolves url to ip
*/

char				*get_address_info(char *url);

/*
** pack icmp message and prepare for sending
*/

void				pack_msg(t_icmp *icmp_msg, int seq);

/*
** The main ping loop
*/

void				ping_me(char *addr_info, struct sockaddr_in to,
		int ping_sockfd);

/*
** recvmsg wrapper
*/

char				*receive_message(int ping_sockfd, int *rcv, char s[]);

/*
** content upacker for ICMP packets.
*/

int					unpack_msg(char *buffer, int len, char *addr);

/*
** signal handler
*/

void				signalhandler(int singal_number);

/*
** Working around broken alarm
*/

void				sleeper(int time);

/*
** Print summary
*/

void				print_summary(void);
int					packet_loss_calculation(struct timeval starttime);
int					elapsed_time_calculation(struct timeval starttime,
		int bias);

/*
** help message just coz..
*/

void				help(void);

/*
** end
*/

#endif
