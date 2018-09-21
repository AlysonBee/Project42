/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:17:57 by angonyam          #+#    #+#             */
/*   Updated: 2018/07/31 07:17:58 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../ftp.h"

void		client_op(int sockfd);
int			check_command_string(char buffer[],
		char *command);
char		*normalize(char *str);
char		wordcount_check(char buffer[]);
char		*terminate_str(char *str);

#endif
