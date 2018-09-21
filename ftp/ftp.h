/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:17:39 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/31 07:17:41 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTP_H
# define FTP_H

# include <stdio.h>
# include "libft/libft.h"
# include <sys/socket.h>
# include <netinet/in.h>
# include <sys/mman.h>
# include <arpa/inet.h>

# define CLIENT 1
# define SERVER 2
# define MAX_MSG_LEN 2048

typedef struct sockaddr_in	t_sockaddr_in;
typedef struct sockaddr		t_sockaddr;

void						usage(int val);
void						error(char *from_where);
t_sockaddr_in				setup_client_addr(char *address, int port);
t_sockaddr_in				setup_server_addr(char *address);
unsigned char				*message_protocol(char *message);
void						send_cycle(unsigned char *content,
		int sockfd);
unsigned char				*write_magic_num(unsigned char *content,
							char *length, char *message);
size_t						number_len(size_t number);
char						*unpack(char buffer[]);
size_t						edit_len(unsigned char *message);
int							map_buffer(unsigned char **file,
		char *message_length, size_t filesize);
void						file_segmentation(unsigned char *filestream,
		int sockfd);
void						file_seg_recv(int sockfd, char *filename);
unsigned char				*send_file(char *filename);
void						unpack_test(unsigned char *content);
unsigned char				*write_word_len(unsigned char *content,
		char *length, size_t *i);
unsigned char				*write_magic(unsigned char *content,
		size_t *i);
unsigned char				*write_file_magic(unsigned char *content,
		char *length, char *message, size_t size);
void						client_shell(int sockfd);
int							scan_for_file(char *filename);
void						get_or_put(char *buffer, int sockfd);
int							scan_server_file(char *filename);
void						recieve_terminal_output(void);
void						handle_ls(char *line);

#endif
