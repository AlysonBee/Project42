
#ifndef TRACEROUTE_H
# define TRACEROUTE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <unistd.h>
# include <pthread.h>
# include <poll.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/ipc.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>
# include <sys/sem.h>
# include <sys/select.h>
# include <sys/un.h>
# include <netinet/ip.h>
# include <netinet/ip_icmp.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <sys/time.h>

/*
** Libft functions
*/

char	*ft_strdup(const char *s1);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);

/*
** Message packing
*/

void    *pack_msg(int i, char *ip, unsigned char buff[]);

/*
** Get address info
*/

char	*get_address_info(char *url);

/*
** main tracer loop
*/

void	tracer_tong(char *addr_info, struct sockaddr_in to,
	int sockfd);

/*
** basic error and exit
*/

void	error_and_exit(char *msg);

#endif 
