



#include "matt_daemon.h"

#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>

void			error_and_exit(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

void			listening(int fd_log)
{
	int					sockfd;
	struct sockaddr_in	addr;

	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sockfd < 0)
		error_and_exit("Error : socket");
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(4242);
	if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
		error_and_exit("Error : bind");
	if (listen(sockfd, 4) < 0)
		error_and_exit("Error : listeninig");
	printf("listening successful\n");
	Matt_Daemon(sockfd, addr, fd_log);
}

