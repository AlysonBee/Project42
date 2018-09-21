/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 07:17:48 by angonyam          #+#    #+#             */
/*   Updated: 2018/08/02 08:02:50 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int			main(int argc, char **argv)
{
	t_sockaddr_in		client_addr;
	int					sockfd;

	if (argc != 3)
		usage(1);
	if (ft_strcmp(argv[1], "localhost") == 0)
		argv[1] = "127.0.0.1";
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		error("socket");
		exit(1);
	}
	client_addr = setup_client_addr(argv[1], ft_atoi(argv[2]));
	if (connect(sockfd, (t_sockaddr *)&client_addr,
				sizeof(client_addr)) < 0)
	{
		error("connect");
		exit(1);
	}
	printf("connecting\n");
	client_op(sockfd);
}
