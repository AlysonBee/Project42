

#include "matt_daemon.h"
#include <sys/select.h>

int			g_process_count = 0;

t_proc		*accept_sockfd(struct sockaddr_in addr, int sockfd, t_proc *id_list)
{
	socklen_t	value;
	int			acceptsock;

	if (g_process_count == 3)
	{
		printf("Notice: Max number of clients reached\n");
		return (id_list);
	}
	value = sizeof(addr);
	acceptsock = accept(sockfd, (struct sockaddr *)&addr, (socklen_t *)&value);
	id_list = process_list_handling(id_list, acceptsock);
	printf("process added\n");
	g_process_count++;
	return (id_list);	
}

/*
** Returns the new maxfd for the select loop
*/

int			reset_fd_list(fd_set *readfds, t_proc *process_list, 
		int maxfd, int sockfd)
{
	t_proc		*trav;

	FD_ZERO(*(&readfds));
	trav = process_list;
	while (trav)
	{
		FD_SET(trav->id, *(&readfds));
		if (trav->id > maxfd)
			maxfd = trav->id;
		trav = trav->next;
	}
	FD_SET(sockfd, *(&readfds));
	return (maxfd);
}

/*
** Write to a log file
*/

void		write_to_log(t_proc *id_list, fd_set readfds, int fd_log)
{
	t_proc	*trav;
	ssize_t	size;
	char	buffer[4096];

	trav = id_list;
	while (trav)
	{
		if (FD_ISSET(trav->id, &readfds))
		{
			bzero(buffer, 4096);
			size = recv(trav->id, buffer, 4096, 0);
			buffer[size] = '\n';
			write(fd_log, buffer, size);
		}
		trav = trav->next;
	}
}

/*
** Main fd loop
*/

int			Matt_Daemon(int sockfd, struct sockaddr_in addr, int fd_log)
{
	int				maxfd;
	int				ret;
	fd_set			readfds;
	t_proc			*id_list;

	id_list = NULL;
	maxfd = sockfd;
	while (42)
	{
		maxfd = reset_fd_list(&readfds, id_list, sockfd, maxfd);
		ret = select(maxfd + 1, &readfds, NULL, NULL, NULL);
		if (ret)
		{
			if (FD_ISSET(sockfd, &readfds))
				id_list = accept_sockfd(addr, sockfd, id_list);
			else
				write_to_log(id_list, readfds, fd_log);
		}
	}
}

