
#include "traceroute.h"

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
	ft_bzero(send_buff, 1024);
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
		ft_memset(&from , 0, sizeof(struct sockaddr_in));
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

