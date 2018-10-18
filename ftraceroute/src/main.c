

#include "traceroute.h"

void	error_and_exit(char *msg)
{
	printf("%s\n", msg);
	exit(1);
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

















