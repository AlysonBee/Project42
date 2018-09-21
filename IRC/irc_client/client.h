/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 12:51:16 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/30 08:02:13 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <unistd.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include "lib/lib.h"
# include "../circular/circle.h"

typedef struct sockaddr		t_sockaddr;
typedef struct sockaddr_in	t_sockaddr_in;
int				g_sockfd;

typedef struct	s_server_list
{
	int						remote_socket;
	t_sockaddr_in			remote_address;
	int						remote_port;
	char					*remote_ip;
	char					*remote_name;
	struct s_server_list	*next;
}				t_serv_list;

typedef struct	s_client
{
	int						port;
	char					*ip;
	char					*prompt;
	t_sockaddr_in			client_addr;
	int						sockfd;
	t_serv_list				*servers;
	char					buffer[4096];
	fd_set					readfds;
	fd_set					writefds;
}				t_client;

void			list(t_serv_list *cluster, t_client *clinet);
char			*name_connection(void);
void			error_and_quit(char *function);
int				sanity_checks(char *input);
int				sanity_checks(char *input);
void			run_client(t_client client);
t_serv_list		*remote_connect(t_serv_list *head,
		int port_num, char *address, t_sockaddr_in new_address);
void			manage_server_cluster(t_client *client);
int				connect_error(char buffer[]);
void			crash_handler(int num);
void			switch_command(t_client *client);
void			help(void);
void			init_client(t_client *client, int argc,
		char **argv);
void			user_prompt(t_client *client,
		char *newname);
int				coming_soon(char buffer[]);
void			disconnection(int sockfd);

#endif
