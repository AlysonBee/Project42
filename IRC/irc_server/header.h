/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 12:50:33 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/30 07:39:10 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/select.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include "lib/lib.h"

typedef struct sockaddr		t_sockaddr;
typedef struct sockaddr_in	t_sockaddr_in;

typedef struct	s_user
{
	int					fd;
	int					ctrl_d;
	int					current_channel;
	char				*buffer;
	char				*username;
	struct s_user		*next;
}				t_user;

typedef struct	s_channel
{
	int					detault_name;
	char				*channel_name;
	t_user				*users;
	struct s_channel	*next;
}				t_chan;

typedef struct	s_server
{
	int					server_comms;
	int					version;
	fd_set				readfds;
	fd_set				writefds;
	int					maxfd;
	int					master_sock;
	t_sockaddr_in		server_addr;
	int					server_params;
	t_chan				*channels;
}				t_serv;

void			join_error(char buffer[]);
t_user			*new_user(int ufd, char *name);
int				is_server_command(char *comm,
		int server_comm, t_user *curr_user);
int				command_sanity_check(char *command);
t_chan			*channels(t_chan *head, char *name);
t_user			*create_user(t_user *userlist, int ufd, char *name);
void			run_server(t_serv server);
void			reset_fds(t_serv *server);
char			*charpush(char *str, char c);
t_chan			*joining_user(t_chan *channels, t_serv *server);
t_chan			*server_io(t_serv *server);
t_user			*write_to_all(t_chan *channel, t_user *curr_user);
char			*who_command(t_user *user, char *channel_name);
char			*who_error(char *command);
t_user			*who(t_user *users,
		int current_user, char *comm, char *channel_name);
t_serv			*msg_command(t_serv *server, t_user *my_info);
t_user			*user_left(t_user *all_users,
		t_user *leaving_user, char *channel_name);
void			server_response(t_serv *server);
t_chan			*leave_channel(t_chan *channel_list,
		t_user *curr_user);
int				userlist_depth(t_user *head);
t_chan			*nick_command(t_chan *channel, t_user *curr_user);
void			nick_error(char buffer[], int *flag,
		char *error_message);
char			*default_username_gen(t_user *userlist);
t_chan			*join_command(t_chan *channel, t_user *curr_user);
t_user			*announce_user_arrival(t_user *userlist,
		t_user *curr_user, char *channel_name);
void			create_prompt(t_user *curr_user,
				char *channel_name);
int				nick_error_handling(t_user *curr_user);
int				join_error_handling(t_user *curr_user);
int				leave_error_handling(t_user *curr_user);
int				disconnect_error_handling(t_user *curr_user);
t_chan			*create_command(t_chan *channel,
		t_user *curr_user, t_chan *curr_chan);
int				create_error_handling(t_user *curr_user);
t_chan			*add_channel(t_chan *channel, char *name);
t_chan			*turn_off_all_other_channels(t_chan *channel,
		t_user *curr_user);
void			closing(int fd);
char			*help(void);
void			sign_catch(int sig);

#endif
