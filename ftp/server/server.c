/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:20:12 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/02 08:04:57 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		main(int argc, char **argv)
{
	t_sockaddr_in		server_addr;
	int					sockfd;
	int					val;
	char				root[4096];

	getcwd(root, 4096);
	g_root_path = ft_strdup(root);
	val = 1;
	if (argc != 2)
		usage(SERVER);
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		error("socket");
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR,
			(char*)&val, sizeof(val));
	server_addr = setup_server_addr(argv[1]);
	if (bind(sockfd, (t_sockaddr *)&server_addr,
				sizeof(server_addr)) < 0)
		error("bind");
	if (listen(sockfd, 5) < 0)
		error("listen");
	printf("listening on port %s .... \n", argv[1]);
	server_op(sockfd, server_addr);
}
