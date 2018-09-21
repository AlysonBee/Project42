/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:20:18 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/31 07:20:29 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../ftp.h"

char			*g_root_path;
void			handle_pwd(void);
void			handle_ls(char *line);
void			server_op(int sockfd, t_sockaddr_in address);
void			server_shell(int sockfd, char buffer[]);
void			handle_cd(char *line, char root[], int sockfd);

/*
** Handle changing directory
*/

char			*create_path(char *newpath, char *plc);
char			*resolve_path(char *path);
char			**set_current_path(void);
void			change_directory(char *line, int sockfd);

#endif
