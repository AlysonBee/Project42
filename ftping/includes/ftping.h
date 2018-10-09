
#ifndef FT_PING_H
# define FT_PING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define ICMP_SIZE	(sizeof(struct icmp));
#define	ICMP_ECHO	8
#define ICMP_ECHOREPLY	0
#define BUF_SIZE	1024
#define NUM		5

typedef struct 		s_icmp
{
	unsigned char		type;
	unsigned char		code;
	unsigned short		checksum;
	unsigned short		id;
	unsigned short		sequence;
}			t_icmp;

typedef struct 		s_ip
{
	unsigned char		hlen:4;
	unsigned char		version:4;
	unsigned char		tos;
	unsigned short		len;
	unsigned short		id;
	unsigned char		offset;
	unsigned char		ttl;
	unsigned char		protocol;
	unsigned short		checksum;
	struct sockaddr_in 	source_ip;
	struct sockaddr_in 	dest_ip;
}			t_ip;


/*
** resolves url to ip
*/

char 	*get_address_info(char *url);












#endif 
