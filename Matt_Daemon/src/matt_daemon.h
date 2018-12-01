
#ifndef MATT_DAEMON_H
# define MATT_DAEMON_H

#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


typedef struct 		s_process_list
{
	int				id;
	struct s_process_list	*next;
}					t_proc;

void				matt_daemon(void);
t_proc				*process_list_handling(t_proc *head, int process_id);
int					init_daemon_check(void);
int					Matt_Daemon(int sockfd, struct sockaddr_in addr, int fd_log);
int					init_daemon_check(void);
void				listening(int fd_log);
void				daemonize(int fd_log);


#endif
