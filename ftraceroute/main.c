

#include "traceroute.h"

void		error_and_exit(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

unsigned short	checksum(char *buffer, int nwords)
{
	unsigned short	*buf;
	unsigned long	sum;

	buf = (unsigned short *)buffer;
	sum = 0;
	while (nwords > 0)
	{
		sum += *buf++;
		nwords--;
	}
	sum = (sum >> 16) + (sum & 0xffff);
	sum += (sum >> 16);
	return (~sum);
}

void	*pack_msg(int i, char *ip, unsigned char buff[])
{
	struct ip		*iphdr;
	struct icmphdr		*icmp;

	iphdr = (struct ip *)buff;
	iphdr->ip_hl = 5;
	iphdr->ip_v = 4;
	iphdr->ip_tos = 0;
	iphdr->ip_len = sizeof(struct ip) + sizeof(struct icmphdr);
	iphdr->ip_id = getpid();
	iphdr->ip_off = 0;
	iphdr->ip_ttl = i;
	iphdr->ip_p = IPPROTO_ICMP;
	inet_pton(AF_INET, ip, &(iphdr->ip_dst));
	iphdr->ip_sum = checksum(buff, 9);
	icmp = (struct icmphdr *)(buff + sizeof(struct ip));
	icmp->type = ICMP_ECHO;
	icmp->code = 0;
	icmp->checksum = 0;
	icmp->un.echo.id = 0;
	icmp->un.echo.sequence = i + 1;
	icmp->checksum = checksum((buff + 20), 4);
	return (buff);
}

char	*user_check(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage : [sudo] %s <hostname/IP>\n",
		argv[0]);
		exit(1);
	}
	if (getuid() != 0)
	{
		printf("Notice : you must be sudo to run\n");
		printf("Usage : [sudo] %s <hostname/IP>\n", argv[0]);
		exit(1);
	}
	if (strcmp(argv[1], "-h") == 0)
	{
		printf("Usage : [sudo] %s <hostname/IP>\n", argv[0]);
		exit(1);
	}
	return (argv[1]);
}

char	*get_address_info(char *url)
{
	struct sockaddr_in		*ip_addr;
	struct addrinfo			hints;
	struct addrinfo			*result;
	int						i;
	char					hostname[100];

	memset(hostname, 0, 100);
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	if ((i = getaddrinfo(url, NULL, &hints, &result)) < 0)
	{
		printf("ft_ping: host unknown\n");
		exit(1);
	}
	ip_addr = (struct sockaddr_in *)result->ai_addr;
	inet_ntop(AF_INET, &ip_addr->sin_addr, hostname, 100);
	return (strdup(hostname));
}

void	elapsedtime(struct timeval starttime)
{
	struct timeval 	currtime;
	double 		curr;
	double	 	start;
	double		diff;

	gettimeofday(&currtime, 0);
	start = (double)starttime.tv_sec * 1000000 + (double)starttime.tv_usec;
	curr = (double)currtime.tv_sec * 1000000 + (double)currtime.tv_usec;
	diff = curr - start;
	diff /= 1000;
	printf("%.3f ms \n", diff);
}

void	unpack_response(int pck_ct, char recv_buff[], char *initial_address,
	struct timeval starttime)
{
	struct ip		*iphdr;
	char			*address;

	iphdr = (struct ip *)recv_buff;
	address = inet_ntoa(iphdr->ip_src);
	printf("%d %s\t\t", pck_ct, address);
	elapsedtime(starttime);
	if (strcmp(address, initial_address) == 0)
	{
		free(initial_address);
		exit(1);
	}
}

void	zero_buffer_and_fromlen(char send_buff[], int *fromlen)
{
	bzero(send_buff, 1024);
	*fromlen = 1;
}

void	tracer_tong(char *addr_info, struct sockaddr_in to, 
	int sockfd)
{
	struct sockaddr_in	from;
	int			packet_count;
	unsigned char		send_buff[1024];
	int			fromlen;
	struct timeval		starttime;

	packet_count = 0;
	while (++packet_count < 30)
	{
		zero_buffer_and_fromlen(send_buff, &fromlen);
		memset(&from , 0, sizeof(struct sockaddr_in));
		pack_msg(packet_count, addr_info, send_buff);
		if (sendto(sockfd, send_buff,
		(sizeof(struct ip) + sizeof(struct icmphdr)), 0,
		(struct sockaddr *)&to, sizeof(to)) == -1)
			error_and_exit("Error : sendto()");
		gettimeofday(&starttime, 0);
		if (recvfrom(sockfd, send_buff, BUFSIZ, 0,  
		(struct sockaddr *)&from , &fromlen) == -1)
			printf("%d *\n", packet_count);
		else
			unpack_response(packet_count, send_buff, addr_info, 
		starttime);
	}
	free(addr_info);
}


int 	main(int argc, char **argv)
{
	char			*hostname;
	int			sockfd;
	struct sockaddr_in	to;
	int			sock_opt;
	struct timeval		timeout;

	sock_opt = 1;
	timeout.tv_sec = 1;
	timeout.tv_usec = 0;
	hostname = user_check(argc, argv);
	if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
		error_and_exit("Error : socket\n");
	setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &sock_opt,
	sizeof(sock_opt));
	setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO,
	(const char *)&timeout, sizeof(timeout));
	memset(&to, 0, sizeof(struct sockaddr_in));
	hostname = get_address_info(hostname);
	to.sin_family = AF_INET;
	inet_pton(AF_INET, hostname, &(to.sin_addr));
	printf("traceroute to %s (%s) 30 hops max, %d byte packets.\n",
	hostname, argv[1], 60);
	tracer_tong(hostname, to, sockfd); 
}

















